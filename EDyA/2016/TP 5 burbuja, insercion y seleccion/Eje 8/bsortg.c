#include "bsortg.h"
#include <stdlib.h>
#include <string.h>

void swap(void *p, void *q){
   void *temp = malloc(sizeof(int));
   memcpy(temp,q,sizeof(int));
   memcpy(q,p,sizeof(int));
   memcpy(p,temp,sizeof(int));
   free(temp);
   return;
}

void bsortg(void* data, int sz, CmpFunc func) {
	int sorted, i;

	do {
		sorted = 1;
		for (i = 0; i < sz - 1; i++)
			if (func(data + i*sizeof(int), data + (i+1)*sizeof(int) ) > 0){
				sorted = 0;
				swap(data + i*sizeof(int), data + (i+1)*sizeof(int) );
			}
	} while (sorted != 1);
}
