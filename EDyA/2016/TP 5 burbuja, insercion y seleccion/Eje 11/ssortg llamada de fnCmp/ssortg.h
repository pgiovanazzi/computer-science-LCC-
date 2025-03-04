#ifndef __SSORTG_H__
#define __SSORTG_H__

typedef int (*CmpFunc)(void *, void *);

void ssortg(void *data[], int sz, CmpFunc cmp);

#endif
