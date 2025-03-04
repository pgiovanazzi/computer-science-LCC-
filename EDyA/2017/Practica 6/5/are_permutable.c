#include <stdio.h>
#include "bsort.h"

#define NELEMS(a) (sizeof((a))/sizeof(int))

int are_permutable(int a1[], int a2[], int sz){
	bsort(a1,sz);
	bsort(a2,sz);
	int i = 0, are_permutable = 1;
	for (; i < sz; i++) {
		if(a1[i] != a2[i])
			return 0;
	}
	return are_permutable;
}

int main(void) {
	int arr1[] = { 2, 4, 1, 3, 7, 8, 6 }, arr2[] = { 4, 1, 2, 6, 8, 2, 7};
	int i;

	printf("arr1: < ");
	for (i = 0; i < NELEMS(arr1); i++) {
		printf("%d, ", arr1[i]);
	}
	printf("> \n");

	printf("arr2: < ");
	for (i = 0; i < NELEMS(arr1); i++) {
		printf("%d, ", arr2[i]);
	}
	printf("> \n");

	printf("are_permutable(arr1,arr2,sz): %d\n", are_permutable(arr1,arr2,NELEMS(arr1)));

  return 0;
}
