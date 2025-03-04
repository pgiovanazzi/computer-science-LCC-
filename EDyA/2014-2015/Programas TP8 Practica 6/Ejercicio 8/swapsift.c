#include "BHeap.h"
#include "swapsift.h"

void swapsift(int *arr, int sz){
	BHeap *h = bheap_create();
	int i;

	for(i = 0; i < sz; i++)
		bheap_insert(h, arr[i]);

	bheap_erase_maximun(h);

	sz = h->nelems+1;

	for(i = 0; i < sz; i++)
		arr[i] = h->data[i];
}