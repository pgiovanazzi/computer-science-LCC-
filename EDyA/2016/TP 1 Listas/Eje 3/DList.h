#ifndef __DList_H__
#define __DList_H__

typedef enum {
	DLIST_TRAVERSAL_ORDER_FORWARD,
	DLIST_TRAVERSAL_ORDER_REWARD
} DListTraversalOrder;

typedef void (*VisitorFuncInt)(int data, void*extra_data);
typedef int (*FComp) (const int *a, const int *b);

/**
 * Los campos son privados, y no deberian ser accedidos
 * desde el código cliente.
 */
typedef struct _DNode {
        int    data;
        struct _DNode *next;
        struct _DNode *prev;
} DNode;

typedef DNode *DList;

#define dlist_data(l)       (l)->data
#define dlist_next(l)       (l)->next
#define dlist_prev(l)		 (l)->prev
#define dlist_nil()         NULL

/**
 * Agrega un elemento al final de la lista, en complejidad O(n).
 *
 * Nota: una lista vacia se representa con un (SList *) NULL.
 */
DList dlist_append(DList list, int data);

/**
 * Agrega un elemento al inicio de la lista, en complejidad O(1).
 *
 * Nota: una lista vacia se representa con un (SList *) NULL.
 */
DList dlist_prepend(DList list, int data);

/**
 * Destruccion de la lista.
 */
void  dlist_destroy(DList list);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void  dlist_foreach(DList list, VisitorFuncInt visit, void *extra_data, DListTraversalOrder order);

/**
 * Dice si un nodo tiene siguiente elemento.
*/
int dlist_has_next(DList node);

/**
 * Dice si un nodo tiene siguiente elemento.
*/
int dlist_has_prev(DList node);

/**
 * Devuelve la longitud de la lista.
*/
int dlist_length(DList list);

/**
 * Devuelve la concatenacion de dos listas.
*/
DList dlist_concat(DList l1, DList l2);

/**
 * Inserta un dado en una lista en una posicion arbitraria.
*/
DList dlist_insert(DList list, int data, int idx);

/**
 * Borra de una lista un dato apuntado en una posicion arbitraria.
*/
DList dlist_remove(DList list, int idx);

/**
 * Dice si el elemento esta en la lista.
*/
int dlist_contains(DList list, const int data);

/**
 * Si el elemento esta en la lista devuelve la posicion del mismo. complejidad o(n*n)
*/
int dlist_index(DList list, const int data);

/**
 * Devuelve una lista con los elementos comunes, (independientemente de la posicion). No se modifican las listas.complejidad o(n*n)
*/
DList dlist_intersect(DList l1, DList l2);

/**
 * Trabaja de la misma forma que la funcion anterior a difierencia que recibe un parametro extra, un puntero
 * a una funcion de comparacion que define la nocion de igualdad al ser usada al comparar elementos por igualdad.complejidad o(n*n)
*/
DList dlist_intersect_custom(DList l1, DList l2, FComp fun);

/**
 * Ordena la lista de acuerdo a un criterio dado por una funcion de comparacion.complejidad o(n*n)
*/
DList dlist_sort(DList list, FComp fun);

#endif /* __DList_H__ */
