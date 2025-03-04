#ifndef __BSORTG_H__
#define __BSORTG_H__
#include <stdlib.h>

typedef int (*CmpFunc)(void *, void *);

void bsortg(void *data, int len, size_t sz, CmpFunc func);


#endif
