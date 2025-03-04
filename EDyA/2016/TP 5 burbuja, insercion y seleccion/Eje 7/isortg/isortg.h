#ifndef __ISORTG_H__
#define __ISORTG_H__

typedef int (*CmpFunc)(void *, void *);

void isortg(void *data[], int sz, CmpFunc cmp);

#endif
