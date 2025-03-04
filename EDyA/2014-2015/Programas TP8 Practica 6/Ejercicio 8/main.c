#include "swapsift.h"
#include <stdio.h>
#include <stdlib.h>

#define LEN(a)		sizeof((a))/sizeof(int)

int main(int argc, char const *argv[])
{
	int arr[] = {10,8,5,4,4,3,1,2}, i;

	for(i = 0; i < LEN(arr); i++)
		printf("%d ", arr[i]);
	puts("");

	swapsift(arr, LEN(arr));

	for(i = 0; i < LEN(arr); i++)
		printf("%d ", arr[i]);
	puts("");

	return 0;
}