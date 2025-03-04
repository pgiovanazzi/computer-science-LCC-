#include "heapify.h"
#include <stdio.h>
#include <stdlib.h>

#define LEN(a)		sizeof((a))/sizeof(int)

int main(int argc, char const *argv[])
{
	int arr[] = {4, 5, 1, 2, 3, 8, 4, 10}, i;

	for(i = 0; i < LEN(arr); i++)
		printf("%d ", arr[i]);
	puts("");

	heapify(arr, LEN(arr));

	for(i = 0; i < LEN(arr); i++)
		printf("%d ", arr[i]);
	puts("");

	return 0;
}