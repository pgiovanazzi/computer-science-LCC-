#ifndef __CSLIST_H__
#define __CSLIST_H__

typedef void (*VisitorFuncInt) (int data, void *extra_data);
typedef int (*FComp)(const int *a,const int *b);

/**
 * Los campos son privados, y no deberian ser accedidos
 * desde el código cliente.
 */
typedef struct _CSNode {
        int    data;
        struct _CSNode *next;
} CSNode;

typedef CSNode *CSList;

#define cslist_data(l)       (l)->data
#define cslist_next(l)       (l)->next
#define cslist_nil()         NULL

/**
 * Agrega un elemento al final de la lista, en complejidad O(n).
 *
 * Nota: una lista vacia se representa con un (SList *) NULL.
 */
CSList cslist_append(CSList list, int data);

/**
 * Agrega un elemento al inicio de la lista, en complejidad O(1).
 *
 * Nota: una lista vacia se representa con un (SList *) NULL.
 */
CSList cslist_prepend(CSList list, int data);

/**
 * Destruccion de la lista.
 */
void  cslist_destroy(CSList list);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void  cslist_foreach(CSList list, VisitorFuncInt visit, void *extra_data);

/**
 * Devuelve la longitud de la lista.
*/

int cslist_length(CSList list);

/**
 * Devuelve la concatenacion de dos listas.
*/

CSList cslist_concat(CSList l1, CSList l2);

/**
 * Inserta un dado en una lista en una posicion arbitraria.
*/

CSList cslist_insert(CSList list, int data, int idx);

/**
 * Borra de una lista un dato apuntado en una posicion arbitraria.
*/

CSList cslist_remove(CSList list, int idx);

/**
 * Dice si el elemento esta en la lista.
*/

int cslist_contains(CSList list, const int data);

/**
 * Si el elemento esta en la lista devuelve la posicion del mismo. complejidad o(n*n)
*/

int cslist_index(CSList list, const int data);

/**
 * Devuelve una lista con los elementos comunes, (independientemente de la posicion). No se modifican las listas.complejidad o(n*n)
*/

CSList cslist_intersect(CSList l1, CSList l2);

/**
 * Trabaja de la misma forma que la funcion anterior a difierencia que recibe un parametro extra, un puntero
 * a una funcion de comparacion que define la nocion de igualdad al ser usada al comparar elementos por igualdad.complejidad o(n*n)
*/

CSList cslist_intersect_custom(CSList l1, CSList l2, FComp fun);

/**
 * Ordena la lista de acuerdo a un criterio dado por una funcion de comparacion.complejidad o(n*n)
*/

CSList cslist_sort(CSList list, FComp fun);

#endif /* __CSLIST_H__ */
