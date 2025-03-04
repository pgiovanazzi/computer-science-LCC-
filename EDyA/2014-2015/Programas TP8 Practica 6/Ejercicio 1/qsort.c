#include "qsort.h"

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int particionar(int data[], int init, int last)
{
	int pivot = data[init], l = init, r = last;

	while (l < r) {
		while (data[l] <= pivot && l < r)
			l++;
		while (data[r] > pivot)
			r--;

		if (l < r)
			swap(&data[l], &data[r]);
	}
	swap(&data[init], &data[r]);
	return r;
}


void myqsort(int data[], int init, int last)
{
	int pivot;

	if (init < last) {
		pivot = particionar(data, init, last);
		myqsort(data, init, pivot-1);
		myqsort(data, pivot + 1, last);
	}
}