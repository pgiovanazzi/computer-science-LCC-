#ifndef __BSORTG_H__
#define __BSORTG_H__

typedef int (*CmpFunc)(void *, void *);

void bsortg(void *arr[], int sz, CmpFunc func);


#endif
