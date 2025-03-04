#include "ssortg.h"
#include <stdio.h>

void swap(void **p, void **q){
	void *t = *p;
	*p = *q;
	*q = t;
}

void ssortg(void *data[], int sz, CmpFunc cmp) {
	int min, i, j, cant = 0;

	for(i = 0; i < sz; i++){
		min = i;
		for(j = i + 1; j < sz; j++){
			if(cmp(&data[j], &data[min]) < 0)
				min = j;
		}
		swap(&data[i], &data[min]);
	}
}
