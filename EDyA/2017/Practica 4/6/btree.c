#include "btree.h"
#include "SLQueue.h"
#include <stdlib.h>

BTree btree_crear() { return NULL; }

void btree_destruir(BTree nodo) {
  if (nodo != NULL) {
    btree_destruir(nodo->left);
    btree_destruir(nodo->right);
    free(nodo);
  }
}

BTree btree_unir(int dato, BTree left, BTree right) {
  BTree nuevoNodo = malloc(sizeof(BTNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->left = left;
  nuevoNodo->right = right;
  return nuevoNodo;
}

void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden,
                    FuncionVisitante visit) {
  if (arbol) {
    if (orden == BTREE_RECORRIDO_IN) {
      btree_recorrer(arbol->left, orden, visit);
      visit(arbol->dato);
      btree_recorrer(arbol->right, orden, visit);
    }
    if (orden == BTREE_RECORRIDO_PRE) {
      visit(arbol->dato);
      btree_recorrer(arbol->left, orden, visit);
      btree_recorrer(arbol->right, orden, visit);
    }
    if (orden == BTREE_RECORRIDO_POST) {
      btree_recorrer(arbol->left, orden, visit);
      btree_recorrer(arbol->right, orden, visit);
      visit(arbol->dato);
    }
  }
}

int btree_suma_elementos(BTree arbol) {
  if (arbol) {
    return arbol->dato + btree_suma_elementos(arbol->left) +
           btree_suma_elementos(arbol->right);
  }
  return 0;
}

int btree_cuenta_nodos(BTree arbol) {
  if (arbol) {
    return 1 + btree_cuenta_nodos(arbol->left) +
           btree_cuenta_nodos(arbol->right);
  }
  return 0;
}

static int max(int a, int b) {
  if (a > b)
    return a;
  return b;
}

int btree_altura(BTree arbol) {
  if (arbol) {
    return 1 + max(btree_altura(arbol->left), btree_altura(arbol->right));
  }
  return 0;
}

void btree_recorrer_extra(BTree arbol, FuncionVisitanteExtra visit,
                          void *extra) {
  if (arbol) {
    btree_recorrer_extra(arbol->left, visit, extra);
    visit(arbol->dato, extra);
    btree_recorrer_extra(arbol->right, visit, extra);
  }
}

void btree_recorrer_bfs(BTree arbol, FuncionVisitanteExtra visit, void *extra) {
  SLQueue cola = slqueue_create();
  BTree nodoActual = arbol;
  cola = slqueue_enqueue(cola, nodoActual);
  while (cola) {
    nodoActual = slqueue_front(cola);
    visit(nodoActual->dato, extra);
    cola = slqueue_dequeue(cola);
    if (nodoActual->left) {
      cola = slqueue_enqueue(cola, nodoActual->left);
    }
		if (nodoActual->right) {
			cola = slqueue_enqueue(cola, nodoActual->right);
		}
  }
}