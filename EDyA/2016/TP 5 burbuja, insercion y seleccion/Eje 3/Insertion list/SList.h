#ifndef __SLIST_H__
#define __SLIST_H__

typedef void (*VisitorFuncInt) (int data, void *extra_data);
typedef int (*FComp)(const int *a,const int *b);

/**
 * Los campos son privados, y no deberian ser accedidos
 * desde el código cliente.
 */
typedef struct _SNode {
        int    data;
        struct _SNode *next;
} SNode;

typedef SNode *SList;

#define slist_data(l)       (l)->data
#define slist_next(l)       (l)->next
#define slist_nil()         NULL

/**
 * Agrega un elemento al final de la lista, en complejidad O(n).
 *
 * Nota: una lista vacia se representa con un (SList *) NULL.
 */
SList slist_append(SList list, int data);

/**
 * Agrega un elemento al inicio de la lista, en complejidad O(1).
 *
 * Nota: una lista vacia se representa con un (SList *) NULL.
 */
SList slist_prepend(SList list, int data);

/**
 * Destruccion de la lista.
 */
void  slist_destroy(SList list);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void  slist_foreach(SList list, VisitorFuncInt visit, void *extra_data);

/**
 * Dice si un nodo tiene siguiente elemento.
*/
int slist_has_next(SList node);

/**
 * Devuelve la longitud de la lista.
*/

int slist_length(SList list);

/**
 * Devuelve la concatenacion de dos listas.
*/

SList slist_concat(SList l1, SList l2);

/**
 * Inserta un dado en una lista en una posicion arbitraria.
*/

SList slist_insert(SList list, int data, int idx);

/**
 * Borra de una lista un dato apuntado en una posicion arbitraria.
*/

SList slist_remove(SList list, int idx);

/**
 * Dice si el elemento esta en la lista.
*/

int slist_contains(SList list, const int data);

/**
 * Si el elemento esta en la lista devuelve la posicion del mismo. complejidad o(n*n)
*/

int slist_index(SList list, const int data);

/**
 * Devuelve una lista con los elementos comunes, (independientemente de la posicion). No se modifican las listas.complejidad o(n*n)
*/

SList slist_intersect(SList l1, SList l2);

/**
 * Trabaja de la misma forma que la funcion anterior a difierencia que recibe un parametro extra, un puntero
 * a una funcion de comparacion que define la nocion de igualdad al ser usada al comparar elementos por igualdad.complejidad o(n*n)
*/

SList slist_intersect_custom(SList l1, SList l2, FComp fun);

/**
 * Ordena la lista de acuerdo a un criterio dado por una funcion de comparacion.complejidad o(n*n)
*/

SList slist_sort(SList list, FComp fun);

#endif /* __SLIST_H__ */
