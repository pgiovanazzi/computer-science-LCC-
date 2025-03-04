#include <stdio.h>
#include "bsortg.h"

#define NELEMS(a) (sizeof((a))/sizeof(int))

int compare(void* a, void* b){
	return *(int *)b-*(int *)a;
}

int main(void) {
	int arr[] = { 1, 4, -2, 3};
	int i;

	bsortg((void *)arr, NELEMS(arr), compare);

	for (i  = 0; i < NELEMS(arr); i++)
		printf("%d ", arr[i]);
	puts("");

  return 0;
}
