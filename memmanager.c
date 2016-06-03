#include "memmanager.h"

memmanager * mem_manager_get(int type) {
	memmanager *m = (memmanager *) malloc(sizeof(memmanager));
	m->type = type;
	m->data = NULL;
	return m;
}

void * mem_malloc(memmanager *m, size_t size) {
	switch(m->type) {
	case KERNEL:
		return malloc(size);
	case BEST_FIT:
		return malloc_best_fit(m, size);
	}
	return m->malloc(size);
}

void mem_free(memmananger *m, void *ptr) {
	m->free(ptr);
}
