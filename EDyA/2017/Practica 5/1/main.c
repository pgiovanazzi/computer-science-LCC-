#include "tablahash.h"
#include <stdio.h>
#include <stdlib.h>

unsigned hash(void *clave) {
  int *p = clave;
  return *p;
}

int main(void) {
  int x = 42, y = 42, z = 3;
  TablaHash *th = tablahash_crear(10, hash);

  tablahash_insertar(th, &x, &z);
	tablahash_insertar(th, &x, &z);

  printf("z : %d\n", *((int *)tablahash_buscar(th, &x)));
  // El error se produce porque las direcciones de memoria son distintas cuando
  // compara la clave de la tabla con la clave que entra, por lo tanto retorna
  // NULL.
  printf("z : %d\n", *((int *)tablahash_buscar(th, &y)));

  tablahash_eliminar(th, &x);

  tablahash_destruir(th);

  return 0;
}
