#include <stdio.h>
#include "ssortg.h"

#define NELEMS(a) (sizeof((a))/sizeof(int))

int compare(void *a, void *b){
	return *(int *)a-*(int *)b;
}

int main(void) {
	int arr[] = { 2, 4, 1, 3, 7, 8, 6 };
	int i;

	ssortg((void *)arr, NELEMS(arr), compare);

	for (i  = 0; i < NELEMS(arr); i++)
		printf("%d ", arr[i]);
	puts("");

  return 0;
}
