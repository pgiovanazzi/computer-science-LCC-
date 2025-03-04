#include <stdio.h>
#include <stdlib.h>
#include "ssortg.h"

#define len(a)      (int)(sizeof(a) / sizeof(*a))

static int fn_call = 0;
int fnCmp(void *x, void *y){
   fn_call++;
   return *(int *)x - *(int *)y;
}

/*
   La funcion de comparacion fnCmp va ser llamada en la primera vez 9 veces
   despus 8 y luego 7 y asi hasta llegar a 1, el resultado sera la suma de
   los primeros 9 numeros naturales, siendo el resultado 45 veses.
*/

int main(int argc, char const *argv[]) {
   int arr[] = { 5, 4, 1, 6, 7, 8, 0, 9, 2, 3 };
   void **ptr_arr = (void **)malloc(sizeof(int *)*len(arr));

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

   printf("La funcion de comparacion fue llamada %d veces.\n", fn_call);

   free(ptr_arr);

   return 0;
}
