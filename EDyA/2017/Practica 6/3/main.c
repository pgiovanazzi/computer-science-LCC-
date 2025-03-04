#include <stdio.h>
#include "isort.h"

#define NELEMS(a) (sizeof((a))/sizeof(int))

int main(void) {
  int arr[] = { 2, 4, 1, 3, 7, 8, 6 };
  int i;

  isort(arr, NELEMS(arr));

  for (i  = 0; i < NELEMS(arr); ++i)
    printf("%d ", arr[i]);
  puts("");

  return 0;
}
