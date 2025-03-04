#include "rssort.h"
#include <stdio.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void rssort(int arr[], int l){
	int max = 0, idx;
	for (idx = 0; idx < l; idx++){
		if (arr[idx] > arr[max])
			max = idx;
	}
	swap(&arr[l-1], &arr[max]);
	if (l > 1)
		rssort(arr, l-1);
}