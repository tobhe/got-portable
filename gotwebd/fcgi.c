/*
 * Copyright (c) 2020-2022 Tracey Emery <tracey@traceyemery.net>
 * Copyright (c) 2013 David Gwynne <dlg@openbsd.org>
 * Copyright (c) 2013 Florian Obser <florian@openbsd.org>
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

#include <arpa/inet.h>
#include <sys/queue.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>

#include <errno.h>
#include <event.h>
#include <imsg.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "got_error.h"

#include "got_compat.h"

#include "proc.h"
#include "gotwebd.h"
#include "tmpl.h"

size_t	 fcgi_parse_record(uint8_t *, size_t, struct request *);
void	 fcgi_parse_begin_request(uint8_t *, uint16_t, struct request *,
	    uint16_t);
void	 fcgi_parse_params(uint8_t *, uint16_t, struct request *, uint16_t);
int	 fcgi_send_response(struct request *, int, const void *, size_t);

void	 dump_fcgi_record_header(const char *, struct fcgi_record_header *);
void	 dump_fcgi_begin_request_body(const char *,
	    struct fcgi_begin_request_body *);
void	 dump_fcgi_end_request_body(const char *,
	    struct fcgi_end_request_body *);

extern int	 cgi_inflight;
extern volatile int client_cnt;

void
fcgi_request(int fd, short events, void *arg)
{
	struct request *c = arg;
	ssize_t n;
	size_t parsed = 0;

	n = read(fd, c->buf + c->buf_pos + c->buf_len,
	    FCGI_RECORD_SIZE - c->buf_pos-c->buf_len);

	switch (n) {
	case -1:
		switch (errno) {
		case EINTR:
		case EAGAIN:
			return;
		default:
			goto fail;
		}
		break;

	case 0:
		log_debug("closed connection");
		goto fail;
	default:
		break;
	}

	c->buf_len += n;

	/*
	 * Parse the records as they are received. Per the FastCGI
	 * specification, the server need only receive the FastCGI
	 * parameter records in full; it is free to begin execution
	 * at that point, which is what happens here.
	 */
	do {
		parsed = fcgi_parse_record(c->buf + c->buf_pos, c->buf_len, c);
		if (parsed != 0) {
			c->buf_pos += parsed;
			c->buf_len -= parsed;
		}
	} while (parsed > 0 && c->buf_len > 0);

	/* Make space for further reads */
	if (parsed != 0)
		if (c->buf_len > 0) {
			bcopy(c->buf + c->buf_pos, c->buf, c->buf_len);
			c->buf_pos = 0;
		}
	return;
fail:
	fcgi_cleanup_request(c);
}

size_t
fcgi_parse_record(uint8_t *buf, size_t n, struct request *c)
{
	struct fcgi_record_header *h;

	if (n < sizeof(struct fcgi_record_header))
		 return 0;

	h = (struct fcgi_record_header*) buf;

	dump_fcgi_record("", h);

	if (n < sizeof(struct fcgi_record_header) + ntohs(h->content_len)
	    + h->padding_len)
		 return 0;

	if (h->version != 1)
		log_warn("wrong version");

	switch (h->type) {
	case FCGI_BEGIN_REQUEST:
		fcgi_parse_begin_request(buf +
		    sizeof(struct fcgi_record_header),
		    ntohs(h->content_len), c, ntohs(h->id));
		break;
	case FCGI_PARAMS:
		fcgi_parse_params(buf + sizeof(struct fcgi_record_header),
		    ntohs(h->content_len), c, ntohs(h->id));
		break;
	case FCGI_STDIN:
	case FCGI_ABORT_REQUEST:
		if (c->sock->client_status != CLIENT_DISCONNECT &&
		    c->outbuf_len != 0) {
			fcgi_send_response(c, FCGI_STDOUT, c->outbuf,
			    c->outbuf_len);
		}

		fcgi_create_end_record(c);
		fcgi_cleanup_request(c);
		return 0;
	default:
		log_warn("unimplemented type %d", h->type);
		break;
	}

	return (sizeof(struct fcgi_record_header) + ntohs(h->content_len)
	    + h->padding_len);
}

void
fcgi_parse_begin_request(uint8_t *buf, uint16_t n,
    struct request *c, uint16_t id)
{
	/* XXX -- FCGI_CANT_MPX_CONN */
	if (c->request_started) {
		log_warn("unexpected FCGI_BEGIN_REQUEST, ignoring");
		return;
	}

	if (n != sizeof(struct fcgi_begin_request_body)) {
		log_warn("wrong size %d != %lu", n,
		    sizeof(struct fcgi_begin_request_body));
		return;
	}

	c->request_started = 1;
	c->id = id;
}

void
fcgi_parse_params(uint8_t *buf, uint16_t n, struct request *c, uint16_t id)
{
	uint32_t name_len, val_len;
	uint8_t *sd, *val;

	if (!c->request_started) {
		log_warn("FCGI_PARAMS without FCGI_BEGIN_REQUEST, ignoring");
		return;
	}

	if (c->id != id) {
		log_warn("unexpected id, ignoring");
		return;
	}

	if (n == 0) {
		gotweb_process_request(c);
		return;
	}

	while (n > 0) {
		if (buf[0] >> 7 == 0) {
			name_len = buf[0];
			n--;
			buf++;
		} else {
			if (n > 3) {
				name_len = ((buf[0] & 0x7f) << 24) +
				    (buf[1] << 16) + (buf[2] << 8) + buf[3];
				n -= 4;
				buf += 4;
			} else
				return;
		}

		if (n == 0)
			return;

		if (buf[0] >> 7 == 0) {
			val_len = buf[0];
			n--;
			buf++;
		} else {
			if (n > 3) {
				val_len = ((buf[0] & 0x7f) << 24) +
					(buf[1] << 16) + (buf[2] << 8) +
					buf[3];
				n -= 4;
				buf += 4;
			} else
				return;
		}

		if (n < name_len + val_len)
			return;

		val = buf + name_len;

		if (c->querystring[0] == '\0' &&
		    val_len < MAX_QUERYSTRING &&
		    name_len == 12 &&
		    strncmp(buf, "QUERY_STRING", 12) == 0) {
			memcpy(c->querystring, val, val_len);
			c->querystring[val_len] = '\0';
		}

		if (c->http_host[0] == '\0' &&
		    val_len < GOTWEBD_MAXTEXT &&
		    name_len == 9 &&
		    strncmp(buf, "HTTP_HOST", 9) == 0) {
			memcpy(c->http_host, val, val_len);
			c->http_host[val_len] = '\0';

			/*
			 * lazily get subdomain
			 * will only get domain if no subdomain exists
			 * this can still work if gotweb server name is the same
			 */
			sd = strchr(c->http_host, '.');
			if (sd)
				*sd = '\0';
		}

		if (c->document_uri[0] == '\0' &&
		    val_len < MAX_DOCUMENT_URI &&
		    name_len == 12 &&
		    strncmp(buf, "DOCUMENT_URI", 12) == 0) {
			memcpy(c->document_uri, val, val_len);
			c->document_uri[val_len] = '\0';
		}

		if (c->server_name[0] == '\0' &&
		    val_len < MAX_SERVER_NAME &&
		    name_len == 11 &&
		    strncmp(buf, "SERVER_NAME", 11) == 0) {
			memcpy(c->server_name, val, val_len);
			c->server_name[val_len] = '\0';
		}

		if (name_len == 5 &&
		    strncmp(buf, "HTTPS", 5) == 0)
			c->https = 1;

		buf += name_len + val_len;
		n -= name_len - val_len;
	}
}

void
fcgi_timeout(int fd, short events, void *arg)
{
	fcgi_cleanup_request((struct request*) arg);
}

int
fcgi_puts(struct template *tp, const char *str)
{
	if (str == NULL)
		return 0;
	return fcgi_gen_binary_response(tp->tp_arg, str, strlen(str));
}

int
fcgi_putc(struct template *tp, int ch)
{
	uint8_t c = ch;
	return fcgi_gen_binary_response(tp->tp_arg, &c, 1);
}

int
fcgi_vprintf(struct request *c, const char *fmt, va_list ap)
{
	char *str;
	int r;

	r = vasprintf(&str, fmt, ap);
	if (r == -1) {
		log_warn("%s: asprintf", __func__);
		return -1;
	}

	r = fcgi_gen_binary_response(c, str, r);
	free(str);
	return r;
}

int
fcgi_printf(struct request *c, const char *fmt, ...)
{
	va_list ap;
	int r;

	va_start(ap, fmt);
	r = fcgi_vprintf(c, fmt, ap);
	va_end(ap);

	return r;
}

int
fcgi_gen_binary_response(struct request *c, const uint8_t *data, int len)
{
	int r;

	if (c->sock->client_status == CLIENT_DISCONNECT)
		return -1;

	if (data == NULL || len == 0)
		return 0;

	/*
	 * special case: send big replies -like blobs- directly
	 * without copying.
	 */
	if (len > sizeof(c->outbuf)) {
		if (c->outbuf_len > 0) {
			fcgi_send_response(c, FCGI_STDOUT,
			    c->outbuf, c->outbuf_len);
			c->outbuf_len = 0;
		}
		return fcgi_send_response(c, FCGI_STDOUT, data, len);
	}

	if (len < sizeof(c->outbuf) - c->outbuf_len) {
		memcpy(c->outbuf + c->outbuf_len, data, len);
		c->outbuf_len += len;
		return 0;
	}

	r = fcgi_send_response(c, FCGI_STDOUT, c->outbuf, c->outbuf_len);
	if (r == -1)
		return -1;

	memcpy(c->outbuf, data, len);
	c->outbuf_len = len;
	return 0;
}

static int
send_response(struct request *c, int type, const uint8_t *data,
    size_t len)
{
	static const uint8_t padding[FCGI_PADDING_SIZE];
	struct fcgi_record_header header;
	struct iovec iov[3];
	struct timespec ts;
	ssize_t nw;
	size_t padded_len, tot;
	int i, err = 0, th = 2000;

	ts.tv_sec = 0;
	ts.tv_nsec = 50;

	memset(&header, 0, sizeof(header));
	header.version = 1;
	header.type = type;
	header.id = htons(c->id);
	header.content_len = htons(len);

	/* The FastCGI spec suggests to align the output buffer */
	tot = sizeof(header) + len;
	padded_len = FCGI_ALIGN(tot);
	if (padded_len > tot) {
		header.padding_len = padded_len - tot;
		tot += header.padding_len;
	}

	iov[0].iov_base = &header;
	iov[0].iov_len = sizeof(header);

	iov[1].iov_base = (void *)data;
	iov[1].iov_len = len;

	iov[2].iov_base = (void *)padding;
	iov[2].iov_len = header.padding_len;

	dump_fcgi_record("resp ", &header);

	/*
	 * XXX: add some simple write heuristics here
	 * On slower VMs, spotty connections, etc., we don't want to go right to
	 * disconnect. Let's at least try to write the data a few times before
	 * giving up.
	 */
	while (tot > 0) {
		nw = writev(c->fd, iov, nitems(iov));
		if (nw == 0) {
			c->sock->client_status = CLIENT_DISCONNECT;
			break;
		}
		if (nw == -1) {
			err++;
			if (errno == EAGAIN && err < th) {
				nanosleep(&ts, NULL);
				continue;
			}
			log_warn("%s: write failure", __func__);
			c->sock->client_status = CLIENT_DISCONNECT;
			return -1;
		}

		if (nw != tot)
			log_debug("%s: partial write: %zu vs %zu", __func__,
			    nw, tot);

		tot -= nw;
		for (i = 0; i < nitems(iov); ++i) {
			if (nw < iov[i].iov_len) {
				iov[i].iov_base += nw;
				iov[i].iov_len -= nw;
				break;
			}
			nw -= iov[i].iov_len;
			iov[i].iov_len = 0;
		}
	}

	return 0;
}

int
fcgi_send_response(struct request *c, int type, const void *data,
    size_t len)
{
	if (c->sock->client_status == CLIENT_DISCONNECT)
		return -1;

	while (len > FCGI_CONTENT_SIZE) {
		if (send_response(c, type, data, len) == -1)
			return -1;

		data += FCGI_CONTENT_SIZE;
		len -= FCGI_CONTENT_SIZE;
	}

	if (len == 0)
		return 0;

	return send_response(c, type, data, len);
}

void
fcgi_create_end_record(struct request *c)
{
	struct fcgi_end_request_body end_request;

	memset(&end_request, 0, sizeof(end_request));
	end_request.app_status = htonl(0); /* script status */
	end_request.protocol_status = FCGI_REQUEST_COMPLETE;

	fcgi_send_response(c, FCGI_END_REQUEST, &end_request,
	    sizeof(end_request));
}

void
fcgi_cleanup_request(struct request *c)
{
	cgi_inflight--;
	client_cnt--;

	evtimer_del(&c->tmo);
	if (event_initialized(&c->ev))
		event_del(&c->ev);

	close(c->fd);
	template_free(c->tp);
	gotweb_free_transport(c->t);
	free(c);
}

void
dump_fcgi_record(const char *p, struct fcgi_record_header *h)
{
	dump_fcgi_record_header(p, h);

	if (h->type == FCGI_BEGIN_REQUEST)
		dump_fcgi_begin_request_body(p,
		    (struct fcgi_begin_request_body *)(h + 1));
	else if (h->type == FCGI_END_REQUEST)
		dump_fcgi_end_request_body(p,
		    (struct fcgi_end_request_body *)(h + 1));
}

void
dump_fcgi_record_header(const char* p, struct fcgi_record_header *h)
{
	log_debug("%sversion:         %d", p, h->version);
	log_debug("%stype:            %d", p, h->type);
	log_debug("%srequestId:       %d", p, ntohs(h->id));
	log_debug("%scontentLength:   %d", p, ntohs(h->content_len));
	log_debug("%spaddingLength:   %d", p, h->padding_len);
	log_debug("%sreserved:        %d", p, h->reserved);
}

void
dump_fcgi_begin_request_body(const char *p, struct fcgi_begin_request_body *b)
{
	log_debug("%srole             %d", p, ntohs(b->role));
	log_debug("%sflags            %d", p, b->flags);
}

void
dump_fcgi_end_request_body(const char *p, struct fcgi_end_request_body *b)
{
	log_debug("%sappStatus:       %d", p, ntohl(b->app_status));
	log_debug("%sprotocolStatus:  %d", p, b->protocol_status);
}
