#include "hsort.h"
#include <stdlib.h>

static void intercambiar(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

static void subir_nodo(int arr[], int nodo) {
  int padre = PADRE(nodo);

  if (padre < 0) {
    return;
  }
  if (arr[nodo] < arr[padre]) {
    intercambiar(&arr[nodo], &arr[padre]);
  }
  subir_nodo(arr, nodo - 1);
}

static void heapify(int arr[], unsigned tam) { subir_nodo(arr, tam - 1); }

static void go_down(int *heap, unsigned sz, unsigned short parentIdx) {
  unsigned short childIdx = 1, isHeap = 0;

  while (childIdx < sz && !isHeap) {
    if (childIdx + 1 < sz)
      if (heap[childIdx + 1] < heap[childIdx])
        childIdx++;
    if (heap[childIdx] < heap[parentIdx]) {
      intercambiar(&heap[parentIdx], &heap[childIdx]);
      parentIdx = childIdx;
      childIdx = CHILD(parentIdx);
    } else
      isHeap = 1;
  }
}

void bheap_erase_minimum(int *heap, unsigned sz) {
  if (sz) {
    heap[0] = heap[sz - 1];
    go_down(heap, sz, 0);
  }
}

int *hsort(int arr[], unsigned tam) {
  heapify(arr, tam);
  int *l = malloc(sizeof(int) * tam);

  for (unsigned i = 0; i < tam; i++) {
    l[i] = arr[0];
    bheap_erase_minimum(arr, tam - i);
  }

  return l;
}