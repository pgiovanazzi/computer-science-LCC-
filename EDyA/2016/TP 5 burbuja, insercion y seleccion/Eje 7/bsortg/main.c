#include <stdio.h>
#include <stdlib.h>
#include "bsortg.h"

#define LEN(a)    (int)(sizeof(a)/sizeof(*a))

int cmp(void *a, void *b){
   return *(int *)a - *(int *)b;
}

int main() {
   int arr[] = { 4, 6, 1, 4, 8}, i;
   void **ptr = (void **)malloc(sizeof(int *)*LEN(arr));

   for (i = 0; i < LEN(arr); i++)
      ptr[i] = &arr[i];
   printf("arr: < ");
   for (i = 0; i < LEN(arr); i++)
      printf("%i, ", *(int *)ptr[i]);
   puts(">");

   bsortg(ptr, LEN(arr), cmp);

   printf("bsortg(arr): < ");
   for (int i = 0; i < LEN(arr); i++)
      printf("%i, ", *(int *)ptr[i]);
   puts(">");

   free(ptr);

   return 0;
}
