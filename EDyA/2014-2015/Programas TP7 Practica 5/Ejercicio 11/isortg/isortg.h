#ifndef __ISORT_H__
#define __ISORT_H__

typedef int (*CmpFunc)(void *, void *);

void isort(void* [], int, CmpFunc);

#endif /*__ISORT_H__*/