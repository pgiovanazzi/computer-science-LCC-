#include "tablahash.h"
#include <stdio.h>
#include <stdlib.h>

int iguales(void *clave1, void *clave2) {
  int *p = clave1;
  int *q = clave2;
  return *p == *q;
}

unsigned hash_doble(void *clave, unsigned sz, unsigned iter) {
  int *p = clave;
  unsigned hash1 = *p % sz;
  unsigned hash2 = 1 + (*p % (sz - 1));
  return hash1 + iter * hash2;
}

// El problema es que compara direcciones de memoria en vez de comparar los
// valores. Esto lleva a que retorne un NULL.

int main(void) {
  int x = 42, y = 12, z = 3, w = 5;
  TablaHash *th = tablahash_crear(7, hash_doble, iguales);

  tablahash_insertar(th, &x, &z);
  tablahash_insertar(th, &y, &w);

  printf("z : %d\n", *((int *)tablahash_buscar(th, &x)));
  printf("w : %d\n", *((int *)tablahash_buscar(th, &y)));
  tablahash_eliminar(th, &x);

  printf("w : %d\n", *((int *)tablahash_buscar(th, &y)));

  tablahash_destruir(th);

  return 0;
}
