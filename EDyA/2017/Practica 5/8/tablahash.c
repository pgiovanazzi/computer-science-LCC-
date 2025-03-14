#include "tablahash.h"
#include <assert.h>
#include <stdlib.h>

/**
 * Crea una nueva tabla Hash vacía, con la capacidad dada.
 */
TablaHash *tablahash_crear(unsigned capacidad, FuncionHash hash,
                           FuncionIgualdad igualdad) {
  // Pedimos memoria para la estructura principal y las casillas.
  TablaHash *tabla = malloc(sizeof(TablaHash));
  tabla->hash = hash;
  tabla->igualdad = igualdad;
  tabla->capacidad = capacidad;
  tabla->tabla = malloc(sizeof(Casilla) * capacidad);
  tabla->numElems = 0;

  // Inicializamos las casillas con datos nulos.
  for (unsigned idx = 0; idx < capacidad; ++idx)
    tabla->tabla[idx] = NULL;

  return tabla;
}

// Factor de carga.
static unsigned redimenciona(unsigned numElem, unsigned capacidad) {
  return ((float)numElem / capacidad > 0.7) ? 1 : 0;
}

/**
 * Inserta el dato en la tabla, asociado a la clave dada.
 */
void tablahash_insertar(TablaHash *tabla, void *clave, void *dato) {
  // Calculamos la posición de la clave dada, de acuerdo a la función hash.
  unsigned idx = tabla->hash(clave);
  idx = idx % tabla->capacidad;
  tabla->numElems++;
  CasillasHash nuevaCasilla = malloc(sizeof(Casilla));
  nuevaCasilla->clave = clave;
  nuevaCasilla->dato = dato;

  nuevaCasilla->sig = tabla->tabla[idx];
  tabla->tabla[idx] = nuevaCasilla;
  if (redimenciona(tabla->numElems, tabla->capacidad))
  	tabla = tablahash_redimensionar(tabla);
}

/**
 * Busca un elemento dado en la tabla, y retorna un puntero al mismo.
 * En caso de no existir, se retorna un puntero nulo.
 */
void *tablahash_buscar(TablaHash *tabla, void *clave) {
  // Calculamos la posición de la clave dada, de acuerdo a la función hash.
  unsigned idx = tabla->hash(clave);
  idx = idx % tabla->capacidad;
  CasillasHash casillaActual = tabla->tabla[idx];

  while (casillaActual) {
    if (tabla->igualdad(casillaActual->clave, clave))
      return casillaActual->dato;
    casillaActual = casillaActual->sig;
  }
  return NULL;
}

/**
 * Elimina un elemento de la tabla.
 */
TablaHash *tablahash_eliminar(TablaHash *tabla, void *clave) {
  // Calculamos la posición de la clave dada, de acuerdo a la función hash.
  unsigned idx = tabla->hash(clave);
  idx = idx % tabla->capacidad;

  if (!tabla->tabla[idx])
    return NULL;

  tabla->numElems--;
  CasillasHash casillaActual = tabla->tabla[idx];
  CasillasHash casillaPrevia = NULL;

  if (tabla->igualdad(casillaActual->clave, clave)) {
    tabla->tabla[idx] = tabla->tabla[idx]->sig;
    free(casillaActual);
    return tabla;
  }

  casillaPrevia = casillaActual;
  casillaActual = casillaActual->sig;
  while (casillaActual) {
    if (tabla->igualdad(casillaActual->clave, clave)) {
      casillaPrevia->sig = casillaActual->sig;
      free(casillaActual);
      return tabla;
    }
    casillaPrevia = casillaActual;
    casillaActual = casillaActual->sig;
  }
  return tabla;
}

/**
 * Destruye la tabla.
 */
void tablahash_destruir(TablaHash *tabla) {
  for (unsigned i = 0; i < tabla->capacidad; i++) {
    while (tabla->tabla[i]) {
      CasillasHash casillaActual = tabla->tabla[i];
      tabla->tabla[i] = tabla->tabla[i]->sig;
      free(casillaActual);
    }
  }
  free(tabla->tabla);
  free(tabla);
}

TablaHash *tablahash_redimensionar(TablaHash *tabla) {
  unsigned j = 0, numElems = tabla->numElems;
  void *arrClave[numElems];
  void *arrDato[numElems];
  for (unsigned i = 0; i < tabla->capacidad; i++) {
    if (tabla->tabla[i]) {
      CasillasHash casillaActual = tabla->tabla[i];
      while (j < numElems && casillaActual) {
        arrClave[j] = casillaActual->clave;
        arrDato[j] = casillaActual->dato;
        casillaActual = casillaActual->sig;
        j++;
      }
    }
  }
  for (unsigned i = 0; i < tabla->capacidad; i++) {
    if (tabla->tabla[i]) {
      while (tabla->tabla[i]) {
        CasillasHash casillaActual = tabla->tabla[i];
        tabla->tabla[i] = tabla->tabla[i]->sig;
        free(casillaActual);
      }
      tabla->tabla[i] = NULL;
    }
  }
  tabla->capacidad*= 2;
	tabla->numElems = 0;
	for (unsigned i = 0; i < numElems; i++)
    tablahash_insertar(tabla, arrClave[i], arrDato[i]);
	return tabla;
}