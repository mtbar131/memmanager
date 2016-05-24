#include "kernel/kernel.h"

#define KERNEL 1
#define BUDDY 2
#define BEST_FIT 3
#define FIRST_FIT 4
#define WORST_FIT 5
#define SIZE_CLS 6

typedef struct memmanager {
	void * (*malloc)(size_t);
	void   (*free)(void *);
} memmanager;

memmanager * mem_manager_get(int type);
