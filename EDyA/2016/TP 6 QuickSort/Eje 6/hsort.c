#include <stdlib.h>
#include "hsort.h"
#include "BHeap.h"

int* hsort(int data[], int l){
  int *d_sorted = malloc(sizeof(int)*l);
  BHeap *h_tmp = bheap_create();

  for (int i = 0; i < l; i++)
    bheap_insert(h_tmp, data[i]);

  int i = 0;
  while (!bheap_is_empty(h_tmp)) {
    d_sorted[i++] = bheap_minimum(h_tmp);
    bheap_erase_minimum(h_tmp);
  }

  bheap_destroy(h_tmp);

  return d_sorted;
}
