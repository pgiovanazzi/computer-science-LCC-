#ifndef __SLIST_H__
#define __SLIST_H__

typedef void (*VisitorFuncInt) (int data, void *extra_data);

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

#endif /* __SLIST_H__ */
