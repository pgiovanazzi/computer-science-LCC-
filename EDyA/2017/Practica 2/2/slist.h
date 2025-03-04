#ifndef __SLIST_H__
#define __SLIST_H__

#include <stddef.h>

typedef void (*FuncionVisitante)(int dato);
typedef int (*CmpFun)(const void *a, const void *b);

typedef struct _SNodo
{
	int dato;
	struct _SNodo *sig;
} SNodo;

typedef SNodo *SList;

/**
 * Devuelve una lista vacía.
 */
SList slist_crear();

/**
 * Destruccion de la lista.
 */
void slist_destruir(SList lista);

/**
 * Determina si la lista es vacía.
 */
int slist_vacia(SList lista);

/**
 * Agrega un elemento al final de la lista.
 */
SList slist_agregar_final(SList lista, int dato);

/**
 * Agrega un elemento al inicio de la lista.
 */
SList slist_agregar_inicio(SList lista, int dato);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void slist_recorrer(SList lista, FuncionVisitante visit);

/**
 * Ordena una lista de acuerdo al criterio dado por una función de comparación
 * (que usa los mismos valores de retorno que strcmp()) pasada por parámetro.
 */

void slist_ordenar(SList lista, CmpFun cmp);

/**
 * obtenga el reverso de una lista.
 */
void slist_reverso(SList lista);

/**
 * dadas dos listas, intercale sus elementos en la lista resultante. Por ejemplo,
 * dadas las listas [1, 2, 3, 4] y [5, 6], debe obtener la lista [1, 5, 2, 6, 3, 4].
 */
SList slist_intercalar(SList lista1, SList lista2);

#endif /* __SLIST_H__ */
