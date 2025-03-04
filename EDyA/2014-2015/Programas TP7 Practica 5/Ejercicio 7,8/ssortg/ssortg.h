#ifndef __SSORT_H__
#define __SSORT_H__

typedef int CmpFunc(void *, void *);

void ssort(void* [], int, CmpFunc);

#endif /* __SSORT_H__ */