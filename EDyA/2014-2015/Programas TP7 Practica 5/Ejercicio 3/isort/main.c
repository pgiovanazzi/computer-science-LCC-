#include "isort.h"
#include <stdio.h>
#include <stdlib.h>

#define LEN(a)		sizeof((a))/sizeof(int)

int main(int argc, char const *argv[])
{
	int arr[] ={1,4,5,2,10,8,3,2}, i;
	
	for(i = 0;i < LEN(arr); i++)
		printf("%d ", arr[i]);
	puts("");

	isort(arr, LEN(arr));

	for(i = 0;i < LEN(arr); i++)
		printf("%d ", arr[i]);
	puts("");

	return 0;
}