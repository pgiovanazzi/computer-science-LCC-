#include <stdio.h>
#include <stdlib.h>
#include "ssortg.h"

#define len(a)    (sizeof(a) / sizeof(*a))

int fnCmp(void *x, void *y){
   return *(int *)x - *(int *)y;
}

int main(int argc, char const *argv[]) {
   int arr[] = { 5, 4, 1, 6, 7, 8, 0};
   void **ptr_arr = malloc(sizeof(int *)*len(arr));

   for (int i = 0; i < len(arr); i++)
      ptr_arr[i] = &arr[i];

   printf("arr: < ");
   for (int i = 0; i < len(arr); i++)
      printf("%i, ", *(int *)ptr_arr[i]);
   printf(" >\n");

   ssortg(ptr_arr, len(arr), fnCmp);
   printf("ssortg(arr): < ");
   for (int i = 0; i < len(arr); i++)
      printf("%i, ", *(int *)ptr_arr[i]);
   printf(" >\n");

   free(ptr_arr);

   return 0;
}
