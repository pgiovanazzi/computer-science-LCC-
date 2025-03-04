#include <stdio.h>
#include "qsort.h"

//qsort no es estable.

#define len(a)    (sizeof(a)/sizeof(*a))

int main(int argc, char const *argv[]) {
  int arr[] = { 4, 6, 7, 1, 3, 9, 2 };

  printf("Arr: < ");
  for (int i = 0; i < len(arr); i++)
    printf("%d, ", arr[i]);
  puts(" >");

  qsort_(arr, 0, len(arr)-1);

  printf("qsort(Arr): < ");
  for (int i = 0; i < len(arr); i++)
    printf("%d, ", arr[i]);
  puts(">");

  return 0;
}
