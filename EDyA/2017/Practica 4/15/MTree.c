#include "MTree.h"
#include <stdlib.h>

MTree mtree_crear(int elem) {
  MTree arbol = malloc(sizeof(Nodo));
  arbol->elem = elem;
  arbol->cantidadDeHijos = 0;
  arbol->primerHermano = NULL;
  arbol->primerHijo = NULL;
  return arbol;
}

void mtree_destruir(MTree arbol) {
  if (arbol) {
    mtree_destruir(arbol->primerHijo);
    mtree_destruir(arbol->primerHermano);
    free(arbol);
  }
}

MTree mtree_agregar_n_hijo(MTree raiz, MTree nodoHijo, int pos) {
  raiz->cantidadDeHijos++;
  if (!pos) {
    nodoHijo->primerHermano = raiz->primerHijo;
    raiz->primerHijo = nodoHijo;
    return raiz;
  } else {
    MTree nodoActual = raiz->primerHijo;
    if (pos == raiz->cantidadDeHijos - 1) {
      while (nodoActual->primerHermano)
        nodoActual = nodoActual->primerHermano;

      nodoActual->primerHermano = nodoHijo;
      return raiz;
    } else {
      int cont = 0;
      MTree nodoPrev = raiz->primerHijo;
      while (cont != pos) {
        if (cont > 0)
          nodoPrev = nodoPrev->primerHermano;
        nodoActual = nodoActual->primerHermano;
        cont++;
      }
      nodoPrev->primerHermano = nodoHijo;
      nodoHijo->primerHermano = nodoActual;
      return raiz;
    }
  }
}

void mtree_recorrer(MTree arbol, FuncionVisitante visit) {
  if (arbol) {
    mtree_recorrer(arbol->primerHijo, visit);
    visit(arbol->elem);
    mtree_recorrer(arbol->primerHermano, visit);
  }
}

void mtree_recorrer_extra(MTree arbol, FuncionVisitanteExtrea visit,
                          void *extra) {
  if (arbol) {
    mtree_recorrer_extra(arbol->primerHijo, visit, extra);
    visit(arbol->elem, extra);
    mtree_recorrer_extra(arbol->primerHermano, visit, extra);
  }
}

static void contar(int dato, void *extra) { (*(int *)extra)++; }

unsigned mtree_cantidad(MTree arbol) {
  unsigned cantidad = 0;
  mtree_recorrer_extra(arbol, contar, &cantidad);
  return cantidad;
}

// funciona mal
static void contar_altura(MTree arbol, int *altura) {
  if (arbol) {
    (*altura)++;
    contar_altura(arbol->primerHijo, altura);
    arbol->primerHermano;
  }
}

unsigned mtree_altura(MTree arbol) {
  unsigned altura = 0;
  contar_altura(arbol, &altura);

  return altura;
}