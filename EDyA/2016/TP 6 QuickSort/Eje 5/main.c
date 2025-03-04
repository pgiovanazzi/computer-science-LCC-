#include <stdio.h>
#include "qsort.h"

#define len(a)    (sizeof(a)/sizeof(*a))

void printArr(int arr[], int l){
  for (int i = 0; i < l; i++)
    printf("%d, ", arr[i]);
}

int main(int argc, char const *argv[]) {
  int arr0[] = { 3, 0, 1, 8, 7, 2, 5, 4, 9, 6 };
  int arr1[] = { 3, 0, 1, 8, 7, 2, 5, 4, 9, 6 };
  int arr2[] = { 3, 0, 1, 8, 7, 2, 5, 4, 9, 6 };
  int arr3[] = { 3, 0, 1, 8, 7, 2, 5, 4, 9, 6 };
  int countCall = 0;

  printf("Arr: < ");
  printArr(arr0,len(arr0));
  puts(">");

  qsort_(arr0, 0, len(arr0)-1, 0, &countCall);

  printf("qsort(Arr, randElem): < ");
  printArr(arr0,len(arr0));
  puts(">");
  printf("Cantidad de llamadas %d veces.\n", countCall);
  countCall = 0;

  qsort_(arr1, 0, len(arr1)-1, 1, &countCall);

  printf("qsort(Arr, lastElem): < ");
  printArr(arr1,len(arr1));
  puts(">");
  printf("Cantidad de llamadas %d veces.\n", countCall);
  countCall = 0;

  qsort_(arr2, 0, len(arr2)-1, 2, &countCall);

  printf("qsort(Arr, midElem): < ");
  printArr(arr2,len(arr2));
  puts(">");
  printf("Cantidad de llamadas %d veces.\n", countCall);
  countCall = 0;

  qsort_(arr3, 0, len(arr3)-1, 3, &countCall);

  printf("qsort(Arr, medianElem): < ");
  printArr(arr3,len(arr3));
  puts(">");
  printf("Cantidad de llamadas %d veces.\n", countCall);

  return 0;
}
