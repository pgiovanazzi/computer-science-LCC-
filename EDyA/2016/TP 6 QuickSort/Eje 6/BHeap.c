#include <stdlib.h>
#include <stdio.h>
#include "BHeap.h"

BHeap *bheap_create(){
  BHeap *heap = malloc(sizeof(BHeap));
  heap->nelems = 0;
  return heap;
}

int bheap_minimum(BHeap *heap){
  if(heap->nelems) return heap->data[0];
}

void bheap_erase_minimum(BHeap *heap){
  if(heap->nelems){
    heap->data[0] = heap->data[heap->nelems-1];
    heap->nelems--;
    int childrens = 1, p = 0;
    while (heap->data[p] > heap->data[childrens] || heap->data[p] > heap->data[childrens + 1]) {
      if(heap->data[childrens] > heap->data[childrens + 1] && heap->nelems > childrens + 1){
        SWAP(heap->data[childrens + 1],heap->data[p]);
        p = childrens + 1;
      }
      else{
        SWAP(heap->data[childrens],heap->data[p]);
        p = childrens;
      }
      childrens = 2 * p + 1;
      if(childrens > heap->nelems -1) break;
    }
  }
  return;
}

void bheap_insert(BHeap *heap, int data){
  int i = heap->nelems++, p;
  heap->data[i] = data;
  if(i % 2 == 0) p = (i-1)/2;
  else p = i/2;
  while (heap->data[i] < heap->data[p] && i) {
    SWAP(heap->data[i],heap->data[p])
    i = p;
    if(i % 2 == 0) p = (i-1)/2;
    else p = i/2;
  }
  return;
}

void bheap_print(BHeap *heap){
  int i = 0;
  printf("<");
  for(; i < heap->nelems; i++)
    printf("%d, ", heap->data[i]);
  printf(">\n");
  return;
}

void bheap_destroy(BHeap *heap){
  free(heap);
  return;
}

int bheap_is_empty(BHeap *heap){
  return heap->nelems == 0;
}
