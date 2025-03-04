#include "qsort.h"

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int particionar(int data[], int init, int last)
{
	int pivot = data[last], i = init, j = last-1;

	while (i != j) {
		if (data[i] <= pivot)
			i++;
		else
			if (data[j] > pivot)
				j--;
			else 
				swap(&data[i], &data[j]);	
	}
	swap(&data[i], &data[last]);
	return i;
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