#include "isortg.h"
#include <stdlib.h>
#include <string.h>

void swap(void *d1, void *d2){
   int mem_sz = d2-d1;
   void *t = malloc(sizeof(mem_sz));
   memcpy(t,d1,mem_sz);
   memcpy(d1,d2,mem_sz);
   memcpy(d2,t,mem_sz);
   free(t);
}

void isortg(void *data[], int sz, CmpFunc cmp){
   for (int i = 0; i < sz; i++) {
      int prev = i, j = i + 1;
      while (prev > -1 && j < sz && cmp(data[prev],data[j]) > 0)
         swap(data[prev--], data[j--]);
   }
}
