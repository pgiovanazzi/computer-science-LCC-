#include "BHeap.h"
#include <stdlib.h>
#include <stdio.h>

BHeap* bheap_create(){
	BHeap *heap = malloc(sizeof(BHeap));
	heap->nelems = -1;
	return heap;
}

int bheap_is_empty(BHeap *heap){
	return heap->nelems == -1;
}

int bheap_maximun(BHeap *heap){
	if(heap->nelems == - 1) return;
	return heap->data[0];
}

void bheap_erase_maximun(BHeap *heap){
	if(heap->nelems == -1)return;

	heap->data[0] = heap->data[heap->nelems--];

	if(heap->nelems > 1){
		int parent = 0, tmp = 0, child1 = parent * 2 + 1, child2 = child1 + 1, maxIdx;
		while (child1 <= heap->nelems && child2 <= heap->nelems){

			if(heap->data[child1] >= heap->data[child2])
				maxIdx = child1;
			else
				maxIdx = child2;
			if (heap->data[parent] < heap->data[maxIdx]) {
				tmp = heap->data[parent];
				heap->data[parent] = heap->data[maxIdx];
				heap->data[maxIdx] = tmp;
			}
			parent = maxIdx;
			child1 = parent * 2 + 1;
			child2 = child1 + 1;
		}
	}
	return;
}

void bheap_insert(BHeap *heap, int elem){
	if(heap->nelems == MAX_HEAP)return;
	
	heap->data[++heap->nelems] = elem;


	if(heap->nelems > 0){
		int child = heap->nelems,parent,tmp;
		parent = (child-1)/2;
	
		while(heap->data[parent] < heap->data[child] && parent > -1 ){
			tmp = heap->data[parent];
			heap->data[parent] = heap->data[child];
			heap->data[child] = tmp;

			child = parent;
			parent = (child-1)/2;
		}
	}
	return;
}

void bheap_print(BHeap *heap){
	if(heap->nelems == -1)return;
	int i;
	for(i = 0; i <= heap->nelems; i++)
		printf("%d ", heap->data[i]);
	return;
}

void  bheap_destroy(BHeap *heap){
	heap->nelems = -1;
	free(heap);
	return;
}