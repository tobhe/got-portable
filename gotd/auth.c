/*
 * Copyright (c) 2022 Stefan Sperling <stsp@openbsd.org>
 * Copyright (c) 2015 Ted Unangst <tedu@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/queue.h>
#include <sys/uio.h>

#include <errno.h>
#include <event.h>
#include <limits.h>
#include <pwd.h>
#include <grp.h>
#include <sha1.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <imsg.h>
#include <unistd.h>

#include "got_error.h"
#include "got_path.h"

#include "gotd.h"
#include "log.h"
#include "auth.h"

static struct gotd_auth {
	pid_t pid;
	const char *title;
	struct gotd_repo *repo;
} gotd_auth;

static void auth_shutdown(void);

static void
auth_sighdlr(int sig, short event, void *arg)
{
	/*
	 * Normal signal handler rules don't apply because libevent
	 * decouples for us.
	 */

	switch (sig) {
	case SIGHUP:
		break;
	case SIGUSR1:
		break;
	case SIGTERM:
	case SIGINT:
		auth_shutdown();
		/* NOTREACHED */
		break;
	default:
		fatalx("unexpected signal");
	}
}

int
gotd_auth_parseuid(const char *s, uid_t *uid)
{
	struct passwd *pw;
	const char *errstr;

	if ((pw = getpwnam(s)) != NULL) {
		*uid = pw->pw_uid;
		if (*uid == UID_MAX)
			return -1;
		return 0;
	}
	*uid = strtonum(s, 0, UID_MAX - 1, &errstr);
	if (errstr)
		return -1;
	return 0;
}

static int
uidcheck(const char *s, uid_t desired)
{
	uid_t uid;

	if (gotd_auth_parseuid(s, &uid) != 0)
		return -1;
	if (uid != desired)
		return -1;
	return 0;
}

static int
parsegid(const char *s, gid_t *gid)
{
	struct group *gr;
	const char *errstr;

	if ((gr = getgrnam(s)) != NULL) {
		*gid = gr->gr_gid;
		if (*gid == GID_MAX)
			return -1;
		return 0;
	}
	*gid = strtonum(s, 0, GID_MAX - 1, &errstr);
	if (errstr)
		return -1;
	return 0;
}

static int
match_identifier(const char *identifier, gid_t *groups, int ngroups,
    uid_t euid, gid_t egid)
{
	int i;

	if (identifier[0] == ':') {
		gid_t rgid;
		if (parsegid(identifier + 1, &rgid) == -1)
			return 0;
		if (rgid == egid)
			return 1;
		for (i = 0; i < ngroups; i++) {
			if (rgid == groups[i])
				break;
		}
		if (i == ngroups)
			return 0;
	} else if (uidcheck(identifier, euid) != 0)
		return 0;

	return 1;
}

static const struct got_error *
auth_check(struct gotd_access_rule_list *rules, const char *repo_name,
    uid_t euid, gid_t egid, int required_auth)
{
	struct gotd_access_rule *rule;
	enum gotd_access access = GOTD_ACCESS_DENIED;
	struct passwd *pw;
	gid_t groups[NGROUPS_MAX];
	int ngroups = NGROUPS_MAX;

	pw = getpwuid(euid);
	if (pw == NULL) {
		if (errno)
			return got_error_from_errno("getpwuid");
		else
			return got_error_set_errno(EACCES, repo_name);
	}

	if (getgrouplist(pw->pw_name, pw->pw_gid, groups, &ngroups) == -1)
		log_warnx("group membership list truncated");

	STAILQ_FOREACH(rule, rules, entry) {
		if (!match_identifier(rule->identifier, groups, ngroups,
		    euid, egid))
			continue;

		access = rule->access;
		if (rule->access == GOTD_ACCESS_PERMITTED &&
		    (rule->authorization & required_auth) != required_auth)
			access = GOTD_ACCESS_DENIED;
	}

	if (access == GOTD_ACCESS_DENIED)
		return got_error_set_errno(EACCES, repo_name);

	if (access == GOTD_ACCESS_PERMITTED)
		return NULL;

	/* should not happen, this would be a bug */
	return got_error_msg(GOT_ERR_NOT_IMPL, "bad access rule");
}

static const struct got_error *
recv_authreq(struct imsg *imsg, struct gotd_imsgev *iev)
{
	const struct got_error *err;
	struct imsgbuf *ibuf = &iev->ibuf;
	struct gotd_imsg_auth iauth;
	size_t datalen;
	uid_t euid;
	gid_t egid;

	log_debug("authentication request received");

	datalen = imsg->hdr.len - IMSG_HEADER_SIZE;
	if (datalen != sizeof(iauth))
		return got_error(GOT_ERR_PRIVSEP_LEN);

	memcpy(&iauth, imsg->data, datalen);

	if (imsg->fd == -1)
		return got_error(GOT_ERR_PRIVSEP_NO_FD);

	if (getpeereid(imsg->fd, &euid, &egid) == -1)
		return got_error_from_errno("getpeerid");

	if (iauth.euid != euid)
		return got_error(GOT_ERR_UID);
	if (iauth.egid != egid)
		return got_error(GOT_ERR_GID);

	log_debug("authenticating uid %d gid %d", euid, egid);

	err = auth_check(&gotd_auth.repo->rules, gotd_auth.repo->name,
	    iauth.euid, iauth.egid, iauth.required_auth);
	if (err) {
		gotd_imsg_send_error(ibuf, PROC_AUTH, iauth.client_id, err);
		return err;
	}

	if (gotd_imsg_compose_event(iev, GOTD_IMSG_ACCESS_GRANTED,
	    PROC_AUTH, -1, NULL, 0) == -1)
		return got_error_from_errno("imsg compose ACCESS_GRANTED");

	return NULL;
}

static void
auth_dispatch(int fd, short event, void *arg)
{
	const struct got_error *err = NULL;
	struct gotd_imsgev *iev = arg;
	struct imsgbuf *ibuf = &iev->ibuf;
	struct imsg imsg;
	ssize_t n;
	int shut = 0;

	if (event & EV_READ) {
		if ((n = imsg_read(ibuf)) == -1 && errno != EAGAIN)
			fatal("imsg_read error");
		if (n == 0)	/* Connection closed. */
			shut = 1;
	}

	if (event & EV_WRITE) {
		n = msgbuf_write(&ibuf->w);
		if (n == -1 && errno != EAGAIN)
			fatal("msgbuf_write");
		if (n == 0)	/* Connection closed. */
			shut = 1;
	}

	for (;;) {
		if ((n = imsg_get(ibuf, &imsg)) == -1)
			fatal("%s: imsg_get", __func__);
		if (n == 0)	/* No more messages. */
			break;

		switch (imsg.hdr.type) {
		case GOTD_IMSG_AUTHENTICATE:
			err = recv_authreq(&imsg, iev);
			if (err)
				log_warnx("%s: %s", gotd_auth.title, err->msg);
			break;
		default:
			log_debug("%s: unexpected imsg %d", gotd_auth.title,
			    imsg.hdr.type);
			break;
		}

		imsg_free(&imsg);
	}

	if (!shut) {
		gotd_imsg_event_add(iev);
	} else {
		/* This pipe is dead. Remove its event handler */
		event_del(&iev->ev);
		event_loopexit(NULL);
	}
}

void
auth_main(const char *title, struct gotd_repolist *repos,
    const char *repo_path)
{
	struct gotd_repo *repo = NULL;
	struct gotd_imsgev iev;
	struct event evsigint, evsigterm, evsighup, evsigusr1;

	gotd_auth.title = title;
	gotd_auth.pid = getpid();
	TAILQ_FOREACH(repo, repos, entry) {
		if (got_path_cmp(repo->path, repo_path,
		    strlen(repo->path), strlen(repo_path)) == 0)
			break;
	}
	if (repo == NULL)
		fatalx("repository %s not found in config", repo_path);
	gotd_auth.repo = repo;

	signal_set(&evsigint, SIGINT, auth_sighdlr, NULL);
	signal_set(&evsigterm, SIGTERM, auth_sighdlr, NULL);
	signal_set(&evsighup, SIGHUP, auth_sighdlr, NULL);
	signal_set(&evsigusr1, SIGUSR1, auth_sighdlr, NULL);
	signal(SIGPIPE, SIG_IGN);

	signal_add(&evsigint, NULL);
	signal_add(&evsigterm, NULL);
	signal_add(&evsighup, NULL);
	signal_add(&evsigusr1, NULL);

	imsg_init(&iev.ibuf, GOTD_FILENO_MSG_PIPE);
	iev.handler = auth_dispatch;
	iev.events = EV_READ;
	iev.handler_arg = NULL;
	event_set(&iev.ev, iev.ibuf.fd, EV_READ, auth_dispatch, &iev);
	if (event_add(&iev.ev, NULL) == -1)
		fatalx("event add");

	event_dispatch();

	auth_shutdown();
}

static void
auth_shutdown(void)
{
	log_debug("%s: shutting down", gotd_auth.title);
	exit(0);
}
