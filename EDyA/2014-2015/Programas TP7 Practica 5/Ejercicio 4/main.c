#include <stdio.h>
#include <stdlib.h>
#define NELEMS(a) (sizeof((a))/sizeof(int))

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void rssort(int arr[], int l){
	int max = 0, idx;
	for (idx = 1; idx < l; idx++){
		if (arr[idx] > arr[max])
			max = idx;
	}
	swap(&arr[l-1], &arr[max]);
	if (l > 1)
		rssort(arr, l-1);
}

int main(void) {
	int arr[] = { 2, 4, 1, 1, 7, 8, 6 };
	int i;

	for (i  = 0; i < NELEMS(arr); i++)
		printf("%d ", arr[i]);
	puts("");

	rssort(arr, NELEMS(arr));

	for (i  = 0; i < NELEMS(arr); i++)
		printf("%d ", arr[i]);
	puts("");

	return 0;
}