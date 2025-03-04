#include "btree.h"
#include <stdio.h>

// Eje 5.b.:
void suma_enteros(int dato, void *extra) { *(int *)extra += dato; }

void cuenta_nodos(int dato, void *extra) { (*(int *)extra)++; }

void imprimir_enteros(int dato, void *extra) { printf("%d ", dato); }

// No se puede implementar el calculo de la altura del arbol con la funcion
// btree_recorrer_extra(). Seria el item 3.
int main(int argc, char *argv[]) {
  int bufferSum = 0, bufferCount = 0;
  BTree ll = btree_unir(5, NULL, NULL);
  BTree lr = btree_unir(2, NULL, NULL);
  BTree l = btree_unir(1, ll, lr);
  BTree rl = btree_unir(3, NULL, NULL);
  BTree rr = btree_unir(7, NULL, NULL);
  BTree r = btree_unir(6, rl, rr);
  BTree raiz = btree_unir(4, l, r);

  btree_recorrer_extra(raiz, imprimir_enteros, NULL);
  puts("");
  btree_recorrer_extra(raiz, suma_enteros, &bufferSum);
  printf("La suma de sus nodos: %d\n", bufferSum);
  btree_recorrer_extra(raiz, cuenta_nodos, &bufferCount);
  printf("Cantidad de nodos: %d\n", bufferCount);

  btree_destruir(raiz);

  return 0;
}