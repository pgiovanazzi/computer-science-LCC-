#include <stdio.h>
#include <stdlib.h>
#include "isortg.h"

#define LEN(a)    (int)(sizeof(a)/sizeof(*a))

int cmpFn(void *x, void* y){
   return *(int *)x - *(int *)y;
}

int main(int argc, char const *argv[]) {
   int arr[] = { 5, 3, 1, 7, 0, 9, 2};
   void **ptr_arr = (void **)malloc(sizeof(int *)*LEN(arr));

   for (int i = 0; i < LEN(arr); i++)
      ptr_arr[i] = &arr[i];

   printf("arr: < ");
   for (int i = 0; i < LEN(arr); i++)
      printf("%i, ", *(int *)ptr_arr[i]);
   puts(" >");

   isortg(ptr_arr, LEN(arr), cmpFn);

   printf("isortg(arr): < ");
   for (int i = 0; i < LEN(arr); i++)
      printf("%i, ", *(int *)ptr_arr[i]);
   puts(" >");

   free(ptr_arr);

   return 0;
}
