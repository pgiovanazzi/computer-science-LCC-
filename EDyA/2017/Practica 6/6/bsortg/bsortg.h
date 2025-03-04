#ifndef __BSORTG_H__
#define __BSORTG_H__
#include <stdlib.h>

typedef int (*CmpFun) (void *, void *);

void bsort(void *datos, int tam, size_t size, CmpFun cmp);

#endif /* __BSORTG_H__ */
