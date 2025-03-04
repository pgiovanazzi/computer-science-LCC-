#include "qsort.h"
#include <stdio.h>
#include <stdlib.h>

#define LEN(a)		sizeof((a))/sizeof(int)

int main(int argc, char const *argv[])
{
	int arr[] = { 1 , 4 , 3 , 5 , 8 , 6 , 7 }, i;

	for(i = 0; i < LEN(arr); i++)
		printf("%d ", arr[i]);
	puts("");

	myqsort(arr, 0, LEN(arr)-1);

	for(i = 0; i < LEN(arr); i++)
		printf("%d ", arr[i]);
	puts("");

	return 0;
}