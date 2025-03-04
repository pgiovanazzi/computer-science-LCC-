#include "BSTree.h"
#include <stdlib.h>

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

static void cargar_elem(BSTree arbol, int *elems, int *inicial) {
  if (arbol) {
    cargar_elem(arbol->izq, elems, inicial);
    elems[(*inicial)++] = arbol->dato;
    cargar_elem(arbol->der, elems, inicial);
  }
}

// Hay que hacerlo con una lista
void bstree_balancear(BSTree *arbol, BSTree izq, BSTree der) {
  if (*arbol) {
    if ((*arbol)->izq && !(*arbol)->der) {
      if ((*arbol)->izq->izq) {
        BSTree tmp = (*arbol)->izq->izq;
        (*arbol)->izq->izq = NULL;
        (*arbol)->der = tmp;
      }
    } else if ((*arbol)->der && !(*arbol)->izq) {
      if ((*arbol)->der->der) {
        BSTree tmp = (*arbol)->der->der;
        (*arbol)->der->der = NULL;
        (*arbol)->izq = tmp;
      }
    }
    bstree_balancear(&(*arbol)->izq);
    bstree_balancear(&(*arbol)->der);
  }
}

int bstree_minimo(BSTree arbol) {
  BSTree nodoActual = arbol;
  while (nodoActual->izq) {
    nodoActual = nodoActual->izq;
  }
  return nodoActual->dato;
}

int bstree_acceder(BSTree arbol, int indice) {
	int sz = bstree_nelementos(arbol);
  int inicial = 0, elems[sz], elem;
  cargar_elem(arbol, elems, &inicial);

	for (size_t i = 0; i < sz; i++)
		if (indice == i) {
			elem = elems[i];
			break;
		}
	return elem;
}
