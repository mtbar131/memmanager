#include "kernel/kernel.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef _MEM_MANAGER_H
#define _MEM_MANAGER_H

#include "best_fit/best_fit.h"

#define KERNEL 1
#define BUDDY 2
#define BEST_FIT 3
#define FIRST_FIT 4
#define WORST_FIT 5
#define SIZE_CLS 6

#define BASE_MEMORY_SIZE 100000 // We will start by allocating this much memory
// to our algorithm. For now user can not go beyond this limit. Think of this as max RAM available

typedef struct memmanager {	
	int type;
	void * data; /* All data structures required by the memory manager */
	void * memory; /* The actual RAM from which malloc will allocate memory */

	void * (*m_malloc)(size_t, struct memmanager *);
	void   (*m_free)(void *, struct memmanager *);
} memmanager;

memmanager * mem_manager_get(int type);
void * mem_malloc(memmanager *m, size_t size);
void mem_free(memmanager *m, void *ptr);

#endif
