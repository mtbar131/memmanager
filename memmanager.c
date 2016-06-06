#include "memmanager.h"

memmanager * mem_manager_get(int type) {
	memmanager *m = (memmanager *) malloc(sizeof(memmanager));
	m->type = type;
	m->data = NULL;
	switch (type) {
		case KERNEL:
			break;
		case BEST_FIT:
			m->m_malloc = malloc_best_fit;
			m->m_free = free_best_fit;
			break;
		case FIRST_FIT:
			m->m_malloc = malloc_first_fit;
			m->m_free = free_first_fit;
			break;
		default:
			free(m);
			return NULL;
	}
	return m;
}

void * mem_malloc(memmanager *m, size_t size) {
	return m->type == KERNEL ? malloc(size) : m->m_malloc(m, size);
}

void mem_free(memmanager *m, void *ptr) {
	m->type == KERNEL ? free(ptr) : m->m_free(m, ptr);
}

int main() {
}
