#ifndef __SLIST_H__
#define __SLIST_H__
#include <stdlib.h>
typedef void (*VisitorFuncInt) (int data, void *extra_data);

/**
 * Los campos son privados, y no deberian ser accedidos
 * desde el código cliente.
 */
 
typedef struct _SList {
		int    data;
		struct _SList *next;
} SList;

#define slist_data(l)       (l)->data
#define slist_next(l)       (l)->next

/**
 * Agrega un elemento al final de la lista, en complejidad O(n).
 *
 * Nota: una lista vacia se representa con un (SList *) NULL.
 */
SList *slist_append(SList *list, int data);

/**
 * Agrega un elemento al inicio de la lista, en complejidad O(1).
 *
 * Nota: una lista vacia se representa con un (SList *) NULL.
 */
SList *slist_prepend(SList *list, int data);

/**
 * Destruccion de la lista.
 */
void  slist_destroy(SList *list);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void  slist_foreach(SList *list, VisitorFuncInt visit, void *extra_data);

//si un nodo tiene siguiente elemento.
ushort slist_has_next(SList *list);

//la longitud de una lista.
size_t slist_length(SList *list);

//devuelva la concatenaci ́on de dos listas.
SList *slist_concat(SList *list1, SList *list2);

//inserta un dato en una lista en una posición arbitraria.
SList *slist_insert(SList *list, int data, size_t index);

//borra de una lista un dato apuntado en una posici ́n arbitraria.
SList *slist_remove(SList *list, size_t index);

//que diga si un elemento est ́ en una lista dada.
ushort slist_contains(SList *list, int data);

//devuelva la posición del elemento data si el mismo está en la lista list.
int slist_index(SList *list, int data);

//devuelva una nueva lista con los elementos comunes.
SList *slist_intersect(SList *list1, SList *list2);

//trabaja como la anterior pero recibe un parámetro extra que es un puntero a una función de 
//comparación que permite definir la noción de igualdad a ser usada al comparar elementos por igualdad.
typedef int (*FunComp)(int a, int b);
SList *slist_intersect_custom(SList *l1, SList *l2, FunComp f);

//ordena una lista de acuerdo al criterio dado por la funcón de comparación pasada por parámetro
typedef int (*comparar)(const void *, const void *);
SList *slist_sort(SList *list, comparar com);

#endif /* __SLIST_H__ */
