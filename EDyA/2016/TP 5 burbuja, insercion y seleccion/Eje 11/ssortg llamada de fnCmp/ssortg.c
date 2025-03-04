#include <stdlib.h>
#include <string.h>
#include "ssortg.h"

void swap(void *d1, void *d2){
   int mem_sz = sizeof(int);
   void *tmp = malloc(sizeof(mem_sz));
   memcpy(tmp,d1,mem_sz);
   memcpy(d1,d2,mem_sz);
   memcpy(d2,tmp,mem_sz);
   free(tmp);
}

void ssortg(void *data[], int sz, CmpFunc fn) {
   for (int i = 0; i < sz ; i++) {
      int min = i;
      for (int j = i + 1; j < sz ; j++)
         if ( fn( data[min], data[j] ) > 0 )
            min = j;
      swap( data[i], data[min] );
   }
}
