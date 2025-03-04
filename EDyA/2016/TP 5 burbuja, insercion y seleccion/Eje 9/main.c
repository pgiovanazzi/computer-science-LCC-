#include <stdio.h>
#include <stdlib.h>
#include "bsortg.h"

#define LEN(a) 	(int)(sizeof((a))/sizeof(*a))

int cmp(void *a, void *b){
	return (*(int *)a - *(int *)b);
}

int cmpMayor(void *a, void *b){
	return -(*(int *)a - *(int *)b);
}

int main(void) {
	int arr[] = {3, 4, 1, 2, 7, 5};

	for (int i = 0; i < LEN(arr); i++)
		printf("%d ", arr[i]);
	puts("");

	bsortg(arr, LEN(arr), sizeof(int), cmpMayor);

	for (int i = 0; i < LEN(arr); i++)
		printf("%d ", arr[i]);
	puts("");
    
  return 0;
}
