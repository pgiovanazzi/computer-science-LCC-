#include "bsortg.h"
#include <stdlib.h>
#include <string.h>

void swap(void *p, void *q){
   void *temp = malloc(strlen((char *)q));
   memcpy(temp,q,strlen((char *)q));
   memcpy(q,p,strlen((char *)p));
   memcpy(p,temp,strlen((char *)q));
   free(temp);
   return;
}

void bsortg(void *data[], int sz, CmpFunc func) {
	int sorted, i;

	do {
		sorted = 1;
		for (i = 0; i < sz - 1; i++){
			if (func(data[i], data[i+1] ) > 0){

				sorted = 0;
				swap(data[i], data[i+1]);
			}
      }
	} while (sorted != 1);
}
