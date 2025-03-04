#include "hsort.h"
#include "BHeap.h"

void hsort(int data[], int sz){
	int i;
	BHeap *h = bheap_create();

	for (i = 0; i < sz; i++)
		bheap_insert(h, data[i]);
	
	i = 0;
	while(!bheap_is_empty(h)){
		data[i++] = bheap_minimum(h);
		bheap_erase_minimum(h);
	}

	bheap_destroy(h);

	return;
}