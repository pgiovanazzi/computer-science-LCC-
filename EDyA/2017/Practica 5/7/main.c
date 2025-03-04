#include "tablahash.h"
#include <stdio.h>
#include <stdlib.h>

int iguales(void *clave1, void *clave2) {
  int *p = clave1;
  int *q = clave2;
  return *p == *q;
}

unsigned hash(void *clave) {
  int *p = clave;
  return *p;
}

// El problema es que compara direcciones de memoria en vez de comparar los
// valores. Esto lleva a que retorne un NULL.

int main(void) {
  int x = 42, y = 12, z = 3, w = 1;
  TablaHash *th = tablahash_crear(3, hash, iguales);

  tablahash_insertar(th, &x, &z);
  tablahash_insertar(th, &y, &w);
  tablahash_insertar(th, &w, &x);
  tablahash_insertar(th, &z, &y);
  printf("x : %d\n", *((int *)tablahash_buscar(th, &x)));
  printf("y : %d\n", *((int *)tablahash_buscar(th, &y)));
  printf("w : %d\n", *((int *)tablahash_buscar(th, &w)));
  printf("z : %d\n", *((int *)tablahash_buscar(th, &z)));
  tablahash_redimensionar(th);
	puts("");
	printf("x : %d\n", *((int *)tablahash_buscar(th, &x)));
  printf("y : %d\n", *((int *)tablahash_buscar(th, &y)));
  printf("w : %d\n", *((int *)tablahash_buscar(th, &w)));
  printf("z : %d\n", *((int *)tablahash_buscar(th, &z)));

  tablahash_destruir(th);

  return 0;
}
