#include "hsort.h"
#include <stdio.h>
#include <stdlib.h>

#define LEN(a)		sizeof((a))/sizeof(int)

int main(int argc, char const *argv[])
{
	int arr[] = { 1, 4, 7, 5 , 3, -1}, i;

	for(i = 0; i < LEN(arr); i++)
		printf("%d ", arr[i]);
	puts("");

	hsort(arr, LEN(arr));

	for(i = 0; i < LEN(arr); i++)
		printf("%d ", arr[i]);
	puts("");

	return 0;
}