#include "pqueue.h"
#include <stdlib.h>

PCola cola_prioridad_crear() {
  PCola nuevaCP = malloc(sizeof(pqueue));
  nuevaCP->elementos = 0;
  return nuevaCP;
}

int cola_prioridad_es_vacia(PCola cp) { return (cp->elementos < 1) ? 1 : 0; }

static void undir(PCola cp, int padre) {
  int cantHijos = 0;
  int hijoIzq = HIJOS(padre);
  int hijoDer = HIJOS(padre) + 1;

  if (hijoIzq < cp->elementos)
    cantHijos++;
  if (hijoDer < cp->elementos)
    cantHijos++;

  if (cantHijos == 0)
    return;

  if (cantHijos == 1)
    if (cp->datos[hijoIzq] < cp->datos[padre]) {
      INTERCAMBIAR(cp->datos[hijoIzq], cp->datos[padre]);
      undir(cp, hijoIzq);
    }

  if (cantHijos == 2)
    if (cp->datos[hijoIzq] < cp->datos[hijoDer]) {
      if (cp->datos[hijoIzq] < cp->datos[padre]) {
        INTERCAMBIAR(cp->datos[hijoIzq], cp->datos[padre]);
        undir(cp, hijoIzq);
      }
    } else {
      if (cp->datos[hijoDer] < cp->datos[padre]) {
        INTERCAMBIAR(cp->datos[hijoDer], cp->datos[padre]);
        undir(cp, hijoDer);
      }
    }
  return;
}

void cola_prioridad_eliminar_minimo(PCola cp) {
  if (!cola_prioridad_es_vacia(cp)) {
    cp->datos[0] = cp->datos[--cp->elementos];
    undir(cp, 0);
  }
}

int cola_prioridad_obtener_minimo(PCola cp) {
  if (!cola_prioridad_es_vacia(cp))
    return cp->datos[0];
}

static void incrementar_prioridad(PCola cp, int hijo, int datoPrioridad) {
  if (cp->datos[hijo] < datoPrioridad)
    return;

  cp->datos[hijo] = datoPrioridad;
  while (hijo > 0 && cp->datos[PADRE(hijo)] > cp->datos[hijo]) {
    INTERCAMBIAR(cp->datos[PADRE(hijo)], cp->datos[hijo]);
    hijo = PADRE(hijo);
  }
}

void cola_prioridad_insertar(PCola cp, int dato) {
  if (cp->elementos + 1 <= MAX_PQUEUE) {
    cp->elementos++;
    cp->datos[cp->elementos - 1] = dato;
    incrementar_prioridad(cp, cp->elementos - 1, dato);
  }
}

void cola_prioridad_imprimir(PCola cp, FuncionVisitador visitar) {
  for (size_t i = 0; i < cp->elementos; i++) {
    visitar(cp->datos[i]);
  }
}

void cola_prioridad_destruir(PCola cp) { free(cp); }