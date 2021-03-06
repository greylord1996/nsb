#ifndef __PATCHER_SERVICE_H__
#define __PATCHER_SERVICE_H__

#include <stdbool.h>

#include "list.h"

struct vma_area;

struct service {
	const char		*name;
	pid_t			pid;
	uint64_t		handle;
	struct dl_map		*dlm;
	int			sock;
	uint64_t		runner;
	bool			loaded;
};

struct process_ctx_s;
int service_start(struct process_ctx_s *ctx, struct service *plugin);
int service_stop(struct process_ctx_s *ctx, struct service *plugin);

struct dl_map;
int service_mmap_dlm(struct process_ctx_s *ctx, const struct service *service,
		     const struct dl_map *dlm, int fd);
int service_munmap_dlm(struct process_ctx_s *ctx, const struct service *service,
		       const struct dl_map *dlm);

ssize_t service_needed_array(struct process_ctx_s *ctx, const struct service *service,
			     uint64_t **needed_array);

int service_transfer_fd(struct process_ctx_s *ctx, struct service *service,
			int fd);

#endif
