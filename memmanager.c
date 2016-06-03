#include "memmanager.h"

memmanager * mem_manager_get(int type) {
	memmanager *m = (memmanager *) malloc(sizeof(memmanager));
	m->type = type;
	m->data = NULL;
	switch (type) {
	case KERNEL:
		m->m_malloc = malloc;
		m->m_free = free;
		break;
	case BEST_FIT:
		m->m_malloc = malloc_best_fit;
		m->m_free = free_best_fit;
		break;
	default:
		m->m_malloc = NULL;
		m->m_free = NULL;	
	}
	return m;
}

void * mem_malloc(memmanager *m, size_t size) {
	m->m_malloc(size, m);
}

void mem_free(memmanager *m, void *ptr) {
	m->m_free(ptr, m);
}

int main() {
}
