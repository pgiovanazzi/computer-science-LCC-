#include "bsortg.h"

void swap(void** p, void** q){
	void* t = *p;
	*p = *q;
	*q = t;
}

void bsortg(void* data[], int sz, CmpFunc cmp) {
	int sorted, i;

	do {
		sorted = 1;
		for (i = 0; i < sz - 1; i++)
			if (cmp(&data[i], &data[i+1]) > 0){
				sorted = 0;
				swap(&data[i], &data[i+1]);
			}
	} while (sorted != 1);
}
