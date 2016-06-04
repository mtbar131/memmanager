#include<stdlib.h>

#ifndef _MEM_MANAGER_H
#define _MEM_MANAGER_H

#define KERNEL 1
#define BUDDY 2
#define BEST_FIT 3
#define FIRST_FIT 4
#define WORST_FIT 5
#define SIZE_CLS 6

#define BASE_MEMORY_SIZE 100000

typedef struct memmanager {
	int type;
	void * data;
	void * memory;
	void * (*m_malloc)(struct memmanager *, size_t);
	void   (*m_free)(struct memmanager *, void *);
} memmanager;

memmanager * mem_manager_get(int type);
void * mem_malloc(memmanager *m, size_t size);
void mem_free(memmanager *m, void *ptr);

#include "kernel/kernel.h"
#include "best_fit/best_fit.h"
#include "first_fit/first_fit.h"

#endif
