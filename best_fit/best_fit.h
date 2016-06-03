#ifndef _BEST_FIT_H
#define _BEST_FIT_H

#include "../memmanager.h"

typedef struct allocated_mem_info {
	void *head; //pointer to head of allocated memory
	size_t size; // amount of memory allocated
} allocated_mem_info;

typedef struct best_fit_data {
	void * memory; // best fits poiters to memory or RAM
	allocated_mem_info mem_info;
	int TOTAL_SIZE; // Total amount of RAM (in bytes) Available
	int FREE; // Total free amount of RAM (in bytes)
	int OCCUPIED; //  Total amount of already occupied RAM
} best_fit_data;

void * malloc_best_fit(size_t size,
		       memmanager *m);

void  free_best_fit(void *ptr,
		    memmanager *m);
#endif
