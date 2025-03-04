#include "BHeap.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
	BHeap* heap = bheap_create();

	bheap_insert(heap,5);
	bheap_insert(heap,15);
	bheap_insert(heap,23);
	bheap_insert(heap,63);
	bheap_insert(heap,47);
	bheap_insert(heap,5);


	printf("Heap binario:\n");
	bheap_print(heap);
	puts("");
	printf("Aplicando el erase_miimum:\n");
	bheap_erase_minimum(heap);
	printf("Heap binario:\n");
	bheap_print(heap);
	puts("");
	printf("El valor minimo es:\n%d\n", bheap_minimum(heap));

	bheap_destroy(heap);
	
	return 0;
}