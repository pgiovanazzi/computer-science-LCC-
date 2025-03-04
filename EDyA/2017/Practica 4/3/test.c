#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

static void imprimir_entero(int data) { printf("%d ", data); }

int main() {
  BTree ll = btree_unir(1, btree_crear(), btree_crear());
  BTree l = btree_unir(2, ll, btree_crear());
  BTree r = btree_unir(3, btree_crear(), btree_crear());
  BTree raiz = btree_unir(4, l, r);

  btree_recorrer(raiz, BTREE_RECORRIDO_IN, imprimir_entero);
  puts("");
  printf("Altura: %d\n", btree_altura(raiz));
  printf("Cantidad de nodos: %d\n", btree_cuenta_nodos(raiz));
  printf("Suma de los elementos: %d\n", btree_suma_elementos(raiz));

  btree_destruir(raiz);

  return 0;
}
