/*
 * Copyright (c) 2018 Stefan Sperling <stsp@openbsd.org>
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

struct got_worktree;

/* status codes */
#define GOT_STATUS_ADD		'A'
#define GOT_STATUS_EXISTS	'E'
#define GOT_STATUS_UPDATE	'U'

/*
 * Attempt to initialize a new work tree on disk.
 * The first argument is the path to a directory where the work tree
 * will be created. The path itself must not yet exist, but the dirname(3)
 * of the path must already exist.
 * The reference provided will be used to determine the new worktree's
 * base commit. The third argument speficies the work tree's path prefix.
 */
const struct got_error *got_worktree_init(const char *, struct got_reference *,
    const char *, struct got_repository *);

/*
 * Attempt to open a worktree at the specified path.
 * The caller must dispose of it with got_worktree_close().
 */
const struct got_error *got_worktree_open(struct got_worktree **, const char *);

/* Dispose of an open work tree. */
void got_worktree_close(struct got_worktree *);

/*
 * Get the path to the repository associated with a worktree.
 */
const char *got_worktree_get_repo_path(struct got_worktree *);

/*
 * Get the path prefix associated with a worktree.
 */
const char *got_worktree_get_path_prefix(struct got_worktree *);

/*
 * Check if a user-provided path prefix matches that of the worktree.
 */
const struct got_error *got_worktree_match_path_prefix(int *,
    struct got_worktree *, const char *);

/*
 * Get the name of a work tree's HEAD reference.
 * The caller must dispose of it with free(3).
 */
char  *got_worktree_get_head_ref_name(struct got_worktree *);

/*
 * Get the work tree's HEAD reference.
 * The caller must dispose of it with free(3).
 */
struct got_reference *got_worktree_get_head_ref(struct got_worktree *);

/*
 * Get the current base commit ID of a worktree.
 */
const struct got_object_id *got_worktree_get_base_commit_id(struct got_worktree *);

/*
 * Set the base commit Id of a worktree.
 */
const struct got_error *got_worktree_set_base_commit_id(struct got_worktree *,
    struct got_repository *, struct got_object_id *);

/* A callback function which is invoked when a path is checked out. */
typedef void (*got_worktree_checkout_cb)(void *, unsigned char, const char *);

/* A callback function which is invoked at cancellation points.
 * May return GOT_ERR_CANCELLED to abort the runing operation. */
typedef const struct got_error *(*got_worktree_cancel_cb)(void *);

/*
 * Attempt to check out files into a work tree from its associated repository
 * and path prefix, and update the work tree's file index accordingly.
 * File content is obtained from blobs within the work tree's path prefix
 * inside the tree corresponding to the work tree's base commit.
 * The checkout progress callback will be invoked with the provided
 * void * argument, and the path of each checked out file.
 */
const struct got_error *got_worktree_checkout_files(struct got_worktree *,
    struct got_repository *, got_worktree_checkout_cb progress, void *,
    got_worktree_cancel_cb, void *);

