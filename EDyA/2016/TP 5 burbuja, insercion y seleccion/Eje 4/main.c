#include "rssort.h"
#include <stdio.h>

#define NELEMS(a) (sizeof(a) / sizeof(int))

void printArr(int arr[], int sz)
{
	printf("< ");
	for (size_t i = 0; i < sz; i++)
		printf("%d, ", arr[i]);
	printf(" >\n");
}

int main(int argc, char const *argv[])
{
	int arr[] = {2, 7, 1, -4, 10, 3};

	printArr(arr, NELEMS(arr));

	printf("rssort(arr,sz,0): ");
	rssort(arr, NELEMS(arr), 0);

	printArr(arr, NELEMS(arr));

	return 0;
}
