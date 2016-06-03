#include "kernel/kernel.h"

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
} memmanager;

memmanager * mem_manager_get(int type);
void * mem_malloc(memmanager *m, size_t size);
void mem_free(memanager *m, void *ptr);
