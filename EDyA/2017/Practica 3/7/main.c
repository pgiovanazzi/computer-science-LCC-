#include <stdio.h>
#include "BHeap.h"

int main(int argc, char const *argv[])
{
	BHeap *heap = bheap_create();

	bheap_insert(heap, 4);
	bheap_insert(heap, 7);
	bheap_insert(heap, 1);
	bheap_insert(heap, 9);
	bheap_insert(heap, 3);
	bheap_insert(heap, 6);

	printf("heap: ");
	bheap_print(heap);

	printf("bheap_minimum(heap) =  %d\n", bheap_minimum(heap));

	printf("bheap_erase_minimum(heap) = ");
	bheap_erase_minimum(heap);
	bheap_print(heap);
	printf("bheap_erase_minimum(heap) = ");
	bheap_erase_minimum(heap);
	bheap_print(heap);
	printf("bheap_erase_minimum(heap) = ");
	bheap_erase_minimum(heap);
	bheap_print(heap);

	printf("bheap_insert(heap, 10) = ");
	bheap_insert(heap, 10);
	bheap_print(heap);
	printf("bheap_insert(heap, -1) = ");
	bheap_insert(heap, -1);
	bheap_print(heap);
	printf("bheap_insert(heap, -4) = ");
	bheap_insert(heap, -4);
	bheap_print(heap);

	bheap_destroy(heap);

	return 0;
}
