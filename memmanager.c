#include "memmanager.h"

memmanager * mem_manager_get(int type) {
	memmanager *m = (memmanager *) malloc(sizeof(memmanager));
	switch(type) {
		case KERNEL:
			m->malloc = malloc;
			m->free = free;
			return m;
	}
	return NULL;
}
