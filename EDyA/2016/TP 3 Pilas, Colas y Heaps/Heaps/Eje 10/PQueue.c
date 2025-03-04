#include "PQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned short bheap_is_empty(BHeap *h) {
  if (h->nelems)
    return 0;
  return 1;
}

BHeap *bheap_create() {
  BHeap *heap = malloc(sizeof(BHeap));
  heap->data = malloc(sizeof(DP) * MAX_PQUEUE);
  heap->nelems = 0;
  return heap;
}

DP bheap_minimum(BHeap *heap) {
  if (heap->nelems)
    return heap->data[0];
}

static void go_down(BHeap *heap, unsigned short parentIdx) {
  unsigned short childIdx = 1, isHeap = 0;

  while (childIdx < heap->nelems && !isHeap) {
    if (childIdx + 1 < heap->nelems)
      if (heap->data[childIdx + 1]->prioty > heap->data[childIdx]->prioty)
        childIdx++;
    if (heap->data[childIdx]->prioty > heap->data[parentIdx]->prioty) {
      SWAP(heap->data[parentIdx], heap->data[childIdx]);
      parentIdx = childIdx;
      childIdx = CHILD(parentIdx);
    } else
      isHeap = 1;
  }
}

BHeap *bheap_erase_minimum(BHeap *heap) {
  if (heap->nelems) {
    heap->data[0] = heap->data[heap->nelems - 1];
    heap->nelems--;
    go_down(heap, 0);
    return heap;
  }
}

BHeap *bheap_insert(BHeap *heap, DP data) {
  int i = heap->nelems++, p = PARENT(i);
  heap->data[i] = data;
  while (heap->data[i]->prioty > heap->data[p]->prioty && i) {
    SWAP(heap->data[i], heap->data[p])
    i = p;
    p = PARENT(i);
  }
  return heap;
}

void bheap_destroy(BHeap *heap) {
  for (size_t i = 0; i < heap->nelems; i++) {
    free(heap->data[i]);
  }
  free(heap);
  return;
}

PQueue *pqueue_create() {
  PQueue *newQueue = malloc(sizeof(PQueue));
  newQueue->heap = bheap_create();
  newQueue->front = 0;
  newQueue->back = newQueue->heap->nelems;
  return newQueue;
}

DP *heapsort(DP *data, int sz) {
  DP *l = malloc(sizeof(DP) * sz);
  BHeap *h = bheap_create();
  int i = 0;
  for (; i < sz; i++)
    h = bheap_insert(h, data[i]);
  i = 0;

  while (!bheap_is_empty(h)) {
    l[i++] = bheap_minimum(h);
    h = bheap_erase_minimum(h);
  }
  bheap_destroy(h);
  return l;
}

void pqueue_enqueue(PQueue *q, int data, int priority) {
  DP elem = malloc(sizeof(dataPrioty));
  elem->d = data;
  elem->prioty = priority;
  q->heap = bheap_insert(q->heap, elem);
  q->back = q->heap->nelems;
}

void pqueue_dequeue(PQueue *q) {
  if (q->back) {
    free(q->heap->data[0]);
    q->heap = bheap_erase_minimum(q->heap);
    q->back = q->heap->nelems;
    for (size_t i = 0; i < q->back - 1; i++)
      if (q->heap->data[i]->prioty < q->heap->data[i + 1]->prioty)
        SWAP(q->heap->data[i], q->heap->data[i + 1])
  }
}

int pequeue_front(PQueue *q) { return q->heap->data[0]->d; }

void pqueue_print(PQueue *q) {
  q->heap->data = heapsort(q->heap->data, q->heap->nelems);
  printf("q: <");
  for (size_t i = 0; i < q->back; i++)
    printf("%d: %d, ", q->heap->data[i]->d, q->heap->data[i]->prioty);
  puts(">");
}

void pqueue_desroy(PQueue *q) {
  for (size_t i = 0; i < q->back; i++) {
    free(q->heap->data[i]);
  }
  bheap_destroy(q->heap);
  free(q);
}
