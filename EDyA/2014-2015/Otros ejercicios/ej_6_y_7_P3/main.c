#include "BTree.h"
#include <stdio.h>
#include <stdlib.h>

static void printInt(int *d, void *extra) {
  printf("%d\n", *d*2);

}

int main() {

  // Declaramos un arbol
  BTree *b1 = btree_create(1, NULL, NULL);
  BTree *b2 = btree_create(2, NULL, NULL);
  BTree *b3 = btree_create(3, b1, b2);
  BTree *b4 = btree_create(4, NULL, NULL);
  BTree *b5 = btree_create(5, b4, b3);
  BTree *b6 = btree_create(6, NULL, NULL);
  BTree *b7 = btree_create(7, NULL, NULL);
  BTree *b8 = btree_create(8, b6, b7);
  BTree *b9 = btree_create(9, b8, b5);

  // Imprimimos el arbol en orden normal
  //btree_foreach(b9, printInt, NULL);

  printf("\n\n");

  // Imprimimos el arbol por niveles
  btree_foreach_level(b9, printInt, NULL);

  // Limpiamos recursos
  btree_destroy(b9);

  return 0;
}
