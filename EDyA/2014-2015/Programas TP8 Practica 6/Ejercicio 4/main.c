#include "qsort_.h"
#include <stdio.h>
#include <stdlib.h>

#define LEN(a)		sizeof((a))/sizeof(int)

int main(int argc, char const *argv[])
{
	int arr[] = { 1 , 4 , 3 , 5 , 8 , 6 , 7 }, i;

	for(i = 0; i < LEN(arr); i++)
		printf("%d ", arr[i]);
	puts("");

	qsort_(arr, 0, 6, 4);

	for(i = 0; i < LEN(arr); i++)
		printf("%d ", arr[i]);
	puts("");

	return 0;
}