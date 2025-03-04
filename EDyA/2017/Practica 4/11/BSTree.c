#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>

void bstree_insertar(BSTree* arbol, int elem) {
  if (!*arbol) {
    *arbol = malloc(sizeof(Nodo));
    (*arbol)->dato = elem;
    (*arbol)->izq = NULL;
    (*arbol)->der = NULL;
  } else if ((*arbol)->dato < elem)
    bstree_insertar(&(*arbol)->der, elem);
  else if ((*arbol)->dato > elem)
    bstree_insertar(&(*arbol)->izq, elem);
}

static void reemplazaar(BSTree* arbol, BSTree* tmp) {
  if (!(*arbol)->der) {
    (*tmp)->dato = (*arbol)->dato;
    *tmp = *arbol;
    *arbol = (*arbol)->izq;
  } else
    reemplazaar(&(*arbol)->der, tmp);
}

void bstree_eliminar(BSTree* arbol, int elem) {
  if (*arbol) {
    BSTree tempo;
    if ((*arbol)->dato < elem)
      bstree_eliminar(&(*arbol)->der, elem);
    else if ((*arbol)->dato > elem)
      bstree_eliminar(&(*arbol)->izq, elem);
    else if ((*arbol)->dato == elem) {
      tempo = *arbol;
      if (!(*arbol)->izq)
        *arbol = (*arbol)->der;
      else if (!(*arbol)->der)
        *arbol = (*arbol)->izq;
      else
        reemplazaar(&(*arbol)->izq, &tempo);

      free(tempo);
    }
  }
}

unsigned bstree_contiene(BSTree arbol, int elem) {
  BSTree nodoActual = arbol;
  unsigned encontrado = 0;
  while (nodoActual && !encontrado) {
    if (nodoActual->dato < elem)
      nodoActual = nodoActual->der;
    else if (nodoActual->dato > elem)
      nodoActual = nodoActual->izq;
    else if (nodoActual->dato == elem)
      encontrado = 1;
  }
  return encontrado;
}

unsigned bstree_nelementos(BSTree arbol) {
  if (arbol)
    return 1 + bstree_nelementos(arbol->der) + bstree_nelementos(arbol->izq);
  return 0;
}

static unsigned max(int a, int b) {
  if (a > b)
    return a;
  return b;
}

unsigned bstree_altura(BSTree arbol) {
  if (arbol)
    return 1 + max(bstree_altura(arbol->der), bstree_altura(arbol->izq));
  return 0;
}

void bstree_recorrer(BSTree arbol, FuncionVisitante visit) {
  if (arbol) {
    bstree_recorrer(arbol->izq, visit);
    visit(arbol->dato);
    bstree_recorrer(arbol->der, visit);
  }
}

void bstree_destruir(BSTree arbol) {
  if (arbol) {
    bstree_destruir(arbol->izq);
    bstree_destruir(arbol->der);
    free(arbol);
  }
}

static void cargar_elem(BSTree arbol, int elems[], int* inicial) {
  if (arbol) {
    cargar_elem(arbol->izq, elems, inicial);
    elems[(*inicial)++] = arbol->dato;
    cargar_elem(arbol->der, elems, inicial);
  }
}

static BSTree cargar_nodos(int* elems, int inicial, int final) {
  if (inicial > final)
    return NULL;

  int mid = (inicial + final) / 2;
  BSTree raiz = malloc(sizeof(Nodo));
  raiz->dato = elems[mid];
  raiz->izq = cargar_nodos(elems, inicial, mid - 1);
  raiz->der = cargar_nodos(elems, mid + 1, final);

  return raiz;
}

void bstree_balancear(BSTree* arbol) {
  int sz = bstree_nelementos(*arbol);
  int elems[sz], inicial = 0;
  cargar_elem(*arbol, elems, &inicial);

  bstree_destruir((*arbol));

  *arbol = cargar_nodos(elems, 0, sz - 1);
}