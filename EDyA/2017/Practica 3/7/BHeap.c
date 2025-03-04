#include "BHeap.h"
#include <stdio.h>
#include <stdlib.h>

BHeap* bheap_create() {
  BHeap* heap = malloc(sizeof(BHeap));
  heap->nelems = 0;
  return heap;
}

int bheap_minimum(BHeap* heap) {
  if (heap->nelems)
    return heap->data[0];
}

static void go_down(BHeap* heap, unsigned short parentIdx) {
  unsigned short childIdx = 1, isHeap = 0;

  while (childIdx < heap->nelems && !isHeap) {
    if (childIdx + 1 < heap->nelems)
      if (heap->data[childIdx + 1] < heap->data[childIdx])
        childIdx++;
    if (heap->data[childIdx] < heap->data[parentIdx]) {
      SWAP(heap->data[parentIdx], heap->data[childIdx]);
      parentIdx = childIdx;
      childIdx = CHILD(parentIdx);
    } else {
      isHeap = 1;
    }
  }
}

void bheap_erase_minimum(BHeap* heap) {
  if (heap->nelems) {
    heap->data[0] = heap->data[heap->nelems - 1];
    heap->nelems--;
    go_down(heap, 0);
  }
}

void bheap_insert(BHeap* heap, int data) {
  int i = heap->nelems++, p = PARENT(i);
  heap->data[i] = data;
  while (heap->data[i] < heap->data[p] && i) {
    SWAP(heap->data[i], heap->data[p])
    i = p;
    p = PARENT(i);
  }
}

void bheap_print(BHeap* heap) {
  int i = 0;
  printf("<");
  for (; i < heap->nelems; i++)
    printf("%d, ", heap->data[i]);
  printf(">\n");
}

void bheap_destroy(BHeap* heap) {
  free(heap);
}
