#include <stdio.h>
#include <stdlib.h>
#include "isortg.h"

#define LEN(a)    (int)(sizeof(a)/sizeof(*a))

static int fn_called = 0;
int cmpFn(void *x, void* y){
   fn_called++;
   return *(int *)x - *(int *)y;
}

/*
   En este caso, la funcion de comparacion cmpFn para este algoritmo va ha ser
   llamada una cantidad de veces que dependera del orden del arreglo que se le
   pase a la funcion. Si el arreglo esta ordenado la funcion de comparacion
   sera llamada 9 veces para un arreglo de 10 elementos, sino sera llamada
   entre 9 y 45 veces, si la funcion fue llamada 45 veces es por que el arreglo
   estaba totalmente desordenado y seria el peor casos.
*/

int main(int argc, char const *argv[]) {
   //int arr[] = { 5, 3, 1, 7, 0, 9, 2, 8, 4};
   int arr2[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
   void **ptr_arr2 = (void **)malloc(sizeof(int *)*LEN(arr2));

   for (int i = 0; i < LEN(arr2); i++)
      ptr_arr2[i] = &arr2[i];

   printf("arr2: < ");
   for (int i = 0; i < LEN(arr2); i++)
      printf("%i, ", *(int *)ptr_arr2[i]);
   puts(" >");

   isortg(ptr_arr2, LEN(arr2), cmpFn);

   printf("isortg(arr2): < ");
   for (int i = 0; i < LEN(arr2); i++)
      printf("%i, ", *(int *)ptr_arr2[i]);
   puts(" >");

   printf("La funcion de comparacion cmpFn fue llamada %d veces.\n", fn_called);

   free(ptr_arr2);

   return 0;
}
