#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

/*
  El problema que trae es que al pasar a la funcion hashtable_lookup las variables (x e y)
  de direcciones de memoria diferentes, en la centencia if esta comparando las
  direcciones de memorias y por lo tanto retorna NULL, a pesar que tengan el mismo
  valor alamacenado y no encontrar el valor (z) asociado.
*/

int equals(void *key1, void *key2) {
  int *p = key1;
  int *q = key2;

  return *p == *q;
}

unsigned int hash(void *key) {
  int *p = key;
  return *p % 10;
}

int main(void) {
  int x = 42, y = 42, z = 3;
  Hashtable *ht = hashtable_new(10, hash, equals);

  hashtable_insert(ht, &x, &z);

  printf("z : %d\n", *((int *)hashtable_lookup(ht, &x)));
  printf("z : %d\n", *((int *)hashtable_lookup(ht, &y)));

  hashtable_delete(ht, &x);

  hashtable_destroy(ht);

  return 0;
}
