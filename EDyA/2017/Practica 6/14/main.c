#include "hsort.h"
#include <stdio.h>

#define NELEMS(a) (sizeof((a)) / sizeof(int))

int main(void) {
  int arr[] = {2, 4, 1, 3,  7,8, 6};
  int i;
	
  int *l = hsort(arr, NELEMS(arr));

  for (i = 0; i < 7; i++)
    printf("%d ", l[i]);
  puts("");

  return 0;
}