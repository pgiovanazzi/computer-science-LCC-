#ifndef __CSList_H__
#define __CSList_H__

typedef void (*VisitorFuncInt) (int data, void *extra_data);

/**
 * Los campos son privados, y no deberian ser accedidos
 * desde el código cliente.
 */

typedef struct _CSList{
	struct _CSList *next;
	int data;
}CSList;

#define slist_data(l)       (l)->data
#define slist_next(l)       (l)->next

/**
 * Agrega un elemento al final de la lista, en complejidad O(n).
 *
 * Nota: una lista vacia se representa con un (SList *) NULL.
 */
CSList *cslist_append(CSList *list, int data);

/**
 * Agrega un elemento al inicio de la lista, en complejidad O(1).
 *
 * Nota: una lista vacia se representa con un (SList *) NULL.
 */
CSList *cslist_prepend(CSList *list, int data);

/**
 * Destruccion de la lista.
 */
void  cslist_destroy(CSList *list);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void  cslist_foreach(CSList *list, VisitorFuncInt visit, void *extra_data);

//si un nodo tiene siguiente elemento.
int cslist_has_next(CSList *list);

//la longitud de una lista.
int cslist_length(CSList *list);

//devuelva la concatenaci ́on de dos listas.
CSList *cslist_concat(CSList *list1, CSList *list2);

//inserta un dato en una lista en una posición arbitraria.
CSList *cslist_insert(CSList *list, int data, unsigned int index);

//borra de una lista un dato apuntado en una posici ́n arbitraria.
CSList *cslist_remove(CSList *list, unsigned int index);

//que diga si un elemento est ́ en una lista dada.
int cslist_contains(CSList *list, int data);

//devuelva la posición del elemento data si el mismo está en la lista list.
unsigned int cslist_index(CSList *list, const int data);

//devuelva una nueva lista con los elementos comunes.
CSList *cslist_intersect(CSList *list1, CSList *list2);

//trabaja como la anterior pero recibe un parámetro extra que es un puntero a una función de 
//comparación que permite definir la noción de igualdad a ser usada al comparar elementos por igualdad.
typedef int (*FunComp)(int a, int b);
CSList *cslist_intersect_custom(CSList *l1, CSList *l2, FunComp f);

//ordena una lista de acuerdo al criterio dado por la funcón de comparación pasada por parámetro
typedef int (*comparar)(const void *, const void *);
CSList *cslist_sort(CSList *list, comparar com);

#endif