#include "BHeap.h"
#include <stdio.h>

BHeap *bheap_marge(BHeap *h1, BHeap *h2) {
  while (h2->nelems) {
    bheap_insert(h1, bheap_minimum(h2));
    bheap_erase_minimum(h2);
  }

  return h1;
}

int main(int argc, char *argv[]) {
  BHeap *h1 = bheap_create();
	BHeap *h2 = bheap_create();

  bheap_insert(h1, 2);
  bheap_insert(h1, 7);
  bheap_insert(h1, 1);
  bheap_insert(h1, 8);

	bheap_print(h1);

  bheap_insert(h2, 9);
  bheap_insert(h2, 5);
  bheap_insert(h2, 3);
  bheap_insert(h2, 4);

	bheap_print(h2);

	bheap_marge(h1,h2);

	bheap_print(h1);

	bheap_destroy(h1);
	bheap_destroy(h2);

  return 0;
}