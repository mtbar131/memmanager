#include<stdlib.h>

#include "../memmanager.h"

#ifndef _BEST_FIT_H
#define _BEST_FIT_H

#define CHUNK_INFO_ARRAY_BASE_SIZE 100

typedef struct chunk_info {
	int start_index;
	size_t size; // amount of memory allocated
} chunk_info;

typedef struct best_fit_data {
	void * memory; // best fits poiters to memory or RAM
	int TOTAL_SIZE; // Total amount of RAM (in bytes) Available
	int FREE; // Total free amount of RAM (in bytes)
	int OCCUPIED; //  Total amount of already occupied RAM

	chunk_info *mem_info;
	int chunk_info_counter;
	int chunk_info_curr_size;

} best_fit_data;

void * malloc_best_fit(memmanager *m, size_t size);

void  free_best_fit(memmanager *m, void *ptr);

void init_best_fit (memmanager *m);

int isMemoryAvailable (memmanager *m, size_t s);

int compare_blocks (const void *, const void *);

/* DEBUG Functions */
void fillMemoryWith(memmanager*, char);

void dumpMemory(memmanager*);
#endif
