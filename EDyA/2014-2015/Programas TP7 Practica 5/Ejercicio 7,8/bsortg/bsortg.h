#ifndef __BSORT_H__
#define __BSORT_H__

typedef int (*CmpFunc)(void* , void* );

void bsortg(void* [], int, CmpFunc);

#endif /* __BSORT_H__ */
