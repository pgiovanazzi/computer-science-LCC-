#include "bsortg.h"
#include <stdlib.h>
#include <string.h>

static void swap(void *p, void *q, size_t size) {
  void *t = malloc(sizeof(size));
  memcpy(t, p, size);
  memcpy(p, q, size);
  memcpy(q, t, size);
  free(t);
}

void bsort(void *datos, int tam, size_t size, CmpFun cmp) {
  int ordenado = 0, i;

  while (!ordenado) {
    ordenado = 1;
    for (i = 0; i < tam - 1; ++i)
      if (cmp(datos + i * size, datos + (i + 1) * size) > 0) {
        ordenado = 0;
        swap(datos + i * size, datos + (i + 1) * size, size);
      }
  }
}
