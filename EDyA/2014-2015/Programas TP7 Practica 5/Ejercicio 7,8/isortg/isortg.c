#include "isortg.h"

void swap(void **a, void **b)
{
	void* p = *a;
	*a = *b;
	*b = p;
}

void isortg(void* arr[], int l, CmpFunc cmp)
{
	int i, j;
	for(i = 0; i < l; i++)
		for(j = 0; j < i; j++){
			if(cmp(&arr[i], &arr[j]) < 0)
				swap(&arr[i], &arr[j]);
		}
}