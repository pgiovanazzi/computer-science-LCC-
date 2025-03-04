#include "bsortg.h"
#include <stdio.h>

#define NELEMS(a) (sizeof((a)) / sizeof(int))

int cmp(void *a, void *b) {
  int x = *(int *)a;
  int y = *(int *)b;
  return x - y;
}

int main(void) {
  int arr[] = {2, 4, 1, 3, 7, 8, 6};
  int i;

  bsort(arr, NELEMS(arr), sizeof(int), cmp);

  for (i = 0; i < NELEMS(arr); ++i)
    printf("%d ", arr[i]);
  puts("");

  return 0;
}
