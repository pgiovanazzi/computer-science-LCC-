#include <stdio.h>
#include "qsort.h"

//qsort no es estable.

#define len(a)    (sizeof(a)/sizeof(*a))

int main(int argc, char const *argv[]) {
  int arr[] = { 3, 0, 1, 8, 7, 2, 5, 4, 9, 6 };

  printf("Arr: < ");
  for (int i = 0; i < len(arr); i++)
    printf("%d, ", arr[i]);
  puts(" >");

  qsort_(arr, 0, len(arr)-1, 0);

  printf("qsort(Arr, randElem): < ");
  for (int i = 0; i < len(arr); i++)
    printf("%d, ", arr[i]);
  puts(">");

  qsort_(arr, 0, len(arr)-1, 1);

  printf("qsort(Arr, lastElem): < ");
  for (int i = 0; i < len(arr); i++)
    printf("%d, ", arr[i]);
  puts(">");

  qsort_(arr, 0, len(arr)-1, 2);

  printf("qsort(Arr, midElem): < ");
  for (int i = 0; i < len(arr); i++)
    printf("%d, ", arr[i]);
  puts(">");

  qsort_(arr, 0, len(arr)-1, 3);

  printf("qsort(Arr, medianElem): < ");
  for (int i = 0; i < len(arr); i++)
    printf("%d, ", arr[i]);
  puts(">");

  return 0;
}
