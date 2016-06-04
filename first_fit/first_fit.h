#include<stdlib.h>

#include "../memmanager.h"

#ifndef _M_FIRST_FIT_H
#define _M_FIRST_FIT_H

void * malloc_first_fit(memmanager *, size_t);
void  free_first_fit(memmanager *, void *);

#endif
