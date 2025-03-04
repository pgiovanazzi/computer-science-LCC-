#include "btree.h"
#include "SLStack.h"
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

// Version recursiva.
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

static void recorrer_en_orden(BTree arbol, FuncionVisitante visit) {
  SLStack pila = slstack_create();
  BTree nodoActual = arbol;
  unsigned hecho = 0;
  while (!hecho) {
    if (nodoActual) {
      pila = slstack_push(pila, nodoActual);
      nodoActual = nodoActual->left;
    } else {
      if (pila) {
        nodoActual = slstack_top(pila);
        visit(nodoActual->dato);
        pila = slstack_pop(pila);
        nodoActual = nodoActual->right;
      } else {
        hecho = 1;
      }
    }
  }
}

static void recorrer_pre_orden(BTree arbol, FuncionVisitante visit) {
  SLStack pila = slstack_create();
  BTree nodoActual = arbol;
  unsigned hecho = 0;
  pila = slstack_push(pila, nodoActual);
  while (!hecho) {
    nodoActual = slstack_top(pila);
    visit(nodoActual->dato);
    pila = slstack_pop(pila);
    if (nodoActual->right) {
      pila = slstack_push(pila, nodoActual->right);
    }
    if (nodoActual->left) {
      pila = slstack_push(pila, nodoActual->left);
    }
    if (!pila) {
      hecho = 1;
    }
  }
}

static void recorrer_post_orden(BTree arbol, FuncionVisitante visit) {
  SLStack pila = slstack_create();
  BTree nodoActual = arbol;
  if (!nodoActual) {
    return;
  }
  do {
    while (nodoActual) {
      if (nodoActual->right)
        pila = slstack_push(pila, nodoActual->right);
      pila = slstack_push(pila, nodoActual);
      nodoActual = nodoActual->left;
    }
		
    nodoActual = slstack_top(pila);
		pila = slstack_pop(pila);
    if (pila && nodoActual->right && slstack_top(pila) == nodoActual->right) {
      pila = slstack_pop(pila);
      pila = slstack_push(pila, nodoActual);
      nodoActual = nodoActual->right;
    } else {
      visit(nodoActual->dato);
      nodoActual = NULL;
    }
  } while (pila);
}

// Version iterativa.
void btree_recorrer_iter(BTree arbol, BTreeOrdenDeRecorrido orden,
                         FuncionVisitante visit) {
  if (orden == BTREE_RECORRIDO_IN) {
    recorrer_en_orden(arbol, visit);
  }
  if (orden == BTREE_RECORRIDO_PRE) {
    recorrer_pre_orden(arbol, visit);
  }
  if (orden == BTREE_RECORRIDO_POST) {
    recorrer_post_orden(arbol, visit);
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