#ifndef __QSORT_H__
#define __QSORT_H__

typedef enum {randElem, lastElem,  midElem, medianElem} type_part;

void qsort_(int data[], int init, int last, type_part tp, int *v);

#endif
