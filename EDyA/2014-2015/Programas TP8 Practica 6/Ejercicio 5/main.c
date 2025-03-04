#include "qsort_.h"
#include <stdio.h>
#include <stdlib.h>

#define LEN(a)		sizeof((a))/sizeof(int)

int main(int argc, char const *argv[])
{
	int arr[] = { 1 , 4 , 3 , 5 , 8 , 6 , 7 },
	arr2[] = { 3 , 4 , 5 }, i;

	for(i = 0; i < LEN(arr2); i++)
		printf("%d ", arr2[i]);
	puts("");

	qsort_(arr2, 0, LEN(arr2)-1 , 4);

	for(i = 0; i < LEN(arr2); i++)
		printf("%d ", arr2[i]);
	puts("");

	return 0;
}