#include "tablahash.h"
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
  tabla->tabla = malloc(sizeof(CasillaHash) * capacidad);
  tabla->numElems = 0;

  // Inicializamos las casillas con datos nulos.
  for (unsigned idx = 0; idx < capacidad; ++idx) {
    tabla->tabla[idx].clave = NULL;
    tabla->tabla[idx].dato = NULL;
  }

  return tabla;
}

/**
 * Inserta el dato en la tabla, asociado a la clave dada.
 */
void tablahash_insertar(TablaHash *tabla, void *clave, void *dato) {
  // Calculamos la posición de la clave dada, de acuerdo a la función hash.
  unsigned idx;
  for (unsigned i = 0; i < tabla->capacidad; i++) {
    idx = tabla->hash(clave, tabla->capacidad, i);
    if (tabla->tabla[idx].clave == NULL || tabla->tabla[idx].clave == &SIM_ELIM)
      break;
  }

  // Si el lugar estaba vacío, incrementamos el número de elementos.
  if (tabla->tabla[idx].clave == NULL || tabla->tabla[idx].clave == &SIM_ELIM)
    tabla->numElems++;

  // Almacenamos los datos ingresados.
  tabla->tabla[idx].clave = clave;
  tabla->tabla[idx].dato = dato;
}

/**
 * Busca un elemento dado en la tabla, y retorna un puntero al mismo.
 * En caso de no existir, se retorna un puntero nulo.
 */
void *tablahash_buscar(TablaHash *tabla, void *clave) {
  // Calculamos la posición de la clave dada, de acuerdo a la función hash.
  unsigned idx;
  int idxReg = -1;
  for (unsigned i = 0; i < tabla->capacidad; i++) {
    idx = tabla->hash(clave, tabla->capacidad, i);
    if (tabla->tabla[idx].clave == &SIM_ELIM && idxReg == -1)
      idxReg = idx;
    if (tabla->igualdad(tabla->tabla[idx].clave, clave) && idxReg != -1) {
      void *dirClave = tabla->tabla[idx].clave;
      void *dirDato = tabla->tabla[idx].dato;
      tabla->tabla[idx].clave = &SIM_ELIM;
      tabla->tabla[idx].dato = NULL;
      tabla->tabla[idxReg].clave = dirClave;
      tabla->tabla[idxReg].dato = dirDato;
      return tabla->tabla[idxReg].dato;
    }
    if (tabla->igualdad(tabla->tabla[idx].clave, clave) && idxReg == -1)
      return tabla->tabla[idx].dato;

    // Si el lugar esta vacío, retornamos un puntero nulo.
    if (tabla->tabla[idx].clave == NULL)
      return NULL;
  }
}

/**
 * Elimina un elemento de la tabla.
 */
void tablahash_eliminar(TablaHash *tabla, void *clave) {
  // Calculamos la posición de la clave dada, de acuerdo a la función hash.
  unsigned idx;
  for (unsigned i = 0; i < tabla->capacidad; i++) {
    idx = tabla->hash(clave, tabla->capacidad, i);
    if (tabla->igualdad(tabla->tabla[idx].clave, clave)) {
      tabla->tabla[idx].clave = &SIM_ELIM;
      tabla->tabla[idx].dato = NULL;
      break;
    }
  }
  // Si el lugar estaba ocupado, decrementamos el número de elementos.
  if (tabla->tabla[idx].clave != NULL)
    tabla->numElems--;
}

/**
 * Destruye la tabla.
 */
void tablahash_destruir(TablaHash *tabla) {
  free(tabla->tabla);
  free(tabla);
}
