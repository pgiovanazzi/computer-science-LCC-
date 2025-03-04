#include <stdio.h>
#include <stdlib.h>
#include "bsortg.h"

#define NELEMS(a) (sizeof((a))/sizeof(int))

int cmp(void *a, void *b){
	return (*(int *)a - *(int *)b);
}

int main(void) {
	int arr[] = { 2, 4, 1, 3, 7, 8, 6 };
	int i;

	for (i = 0; i < NELEMS(arr); i++)
		printf("%d ", arr[i]);
	puts("");

	bsortg((void*)arr, NELEMS(arr), cmp);

	for (i = 0; i < NELEMS(arr); i++)
		printf("%d ", arr[i]);
	puts("");

  return 0;
}
