#include "BSTree.h"
#include <stdlib.h>
#include <stdio.h>

// Version recursiva.
void bstree_insertar(BSTree *arbol, int elem) {
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

// Version iterativa. (mas eficiente)
BSTree btree_insertar_iter(BStree arbol, int elem) {
	BStree qtr = NULL;
  BStree ptr = arbol;
  while (ptr) {
  	qtr = ptr;
  	if (elem <= ptr->elem)
  		ptr = ptr->izq;
  	else
  		ptr = ptr->der;
  }
  BSTree nuevoNodo = malloc(sizeof(Nodo));
  nuevoNodo->elem = elem;
  nuevoNodo->izq = NULL;
  nuevoNodo->der = NULL;
  if (!qtr)
  	return nuevoNodo;
  else
		if (elem < qtr->elem)
			qtr->izq = nuevoNodo;
		else
			qtr->der = nuevoNodo;
}

static void reemplazaar(BSTree *arbol, BSTree *tmp) {
  if (!(*arbol)->der) {
    (*tmp)->dato = (*arbol)->dato;
    *tmp = *arbol;
    *arbol = (*arbol)->izq;
  } else
    reemplazaar(&(*arbol)->der, tmp);
}

void bstree_eliminar(BSTree *arbol, int elem) {
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
