#include "isortg.h"
#include <stdio.h>
#include <stdlib.h>

#define LEN(a)		sizeof((a))/sizeof(int)

int compare(void *a, void *b){
	static int x = 0;
	printf("%d\n", ++x);
	return *(int *)a-*(int *)b;
}

int main(int argc, char const *argv[])
{
	int arr[] ={1,4,5,2,10,8,3,2}, i;
	
	for(i = 0;i < LEN(arr); i++)
		printf("%d ", arr[i]);
	puts("");

	isortg((void *)arr, LEN(arr), compare);

	for(i = 0;i < LEN(arr); i++)
		printf("%d ", arr[i]);
	puts("");

	return 0;
}