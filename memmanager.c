#include "memmanager.h"

memmanager * mem_manager_get(int type) {
	memmanager *m = (memmanager *) malloc(sizeof(memmanager));
	switch(type) {
		case KERNEL:
			/* Every allocator should have its own init fn like kern_init(m)*/
			return m;
	}
	return NULL;
}

void * mem_malloc(memmanager *m, size_t size) {
	return m->malloc(size);
}

void mem_free(memmananger *m, void *ptr) {
	m->free(ptr);
}
