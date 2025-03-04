#include "msort.h"
#include <stdio.h>

int main(void) {
  int arr[] = {2, 4, 9, 3, 6, 7, 8};
  int i;

  marge_sort(arr, 0, NELEMS(arr) - 1);

  for (i = 0; i < NELEMS(arr); i++)
    printf("%d ", arr[i]);
  puts("");

  return 0;
}