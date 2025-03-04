#ifndef __GList_H__
#define __GList_H__

typedef void (*VisitorFuncInt)(void *data, void *extra_data);
typedef int (*FComp)(const void *a,const void *b);

typedef struct _GNode {
  void *data;
  struct _GNode *next;
} GNode;

typedef GNode *GList;

#define glist_next(l)   (l)->next
#define glist_data(l)   (l)->data
#define glist_nil()         NULL

/**
 * Agrega un elemento al final de la lista, en complejidad O(n).
 *
 * Nota: una lista vacia se representa con un (GList *) NULL.
 */
GList glist_append(GList list, void *data);

/**
 * Agrega un elemento al inicio de la lista, en complejidad O(1).
 *
 * Nota: una lista vacia se representa con un (GList *) NULL.
 */
GList glist_prepend(GList list, void *data);

/**
 * Destruccion de la lista.
 */
void  glist_destroy(GList list);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void  glist_foreach(GList list, VisitorFuncInt visit, void *extra_data);

/**
 * Dice si un nodo tiene siguiente elemento.
*/
int glist_has_next(GList node);

/**
 * Devuelve la longitud de la lista.
*/

int glist_length(GList list);

/**
 * Devuelve la concatenacion de dos listas.
*/

GList glist_concat(GList l1, GList l2);

/**
 * Inserta un dado en una lista en una posicion arbitraria.
*/

GList glist_insert(GList list, void *data, int idx);

/**
 * Borra de una lista un dato apuntado en una posicion arbitraria.
*/

GList glist_remove(GList list, int idx);

/**
 * Dice si el elemento esta en la lista.
*/

int glist_contains(GList list, const void *data, FComp cmp);

/**
 * Si el elemento esta en la lista devuelve la posicion del mismo. complejidad o(n*n)
*/

int glist_index(GList list, const void *data, FComp cmp);

/**
 * Devuelve una lista con los elementos comunes, (independientemente de la posicion). No se modifican las listas.complejidad o(n*n)
*/

GList glist_intersect(GList l1, GList l2, FComp cmp);

/**
 * Trabaja de la misma forma que la funcion anterior a difierencia que recibe un parametro extra, un puntero
 * a una funcion de comparacion que define la nocion de igualdad al ser usada al comparar elementos por igualdad.complejidad o(n*n)
*/

GList glist_intersect_custom(GList l1, GList l2, FComp fun);

/**
 * Ordena la lista de acuerdo a un criterio dado por una funcion de comparacion.complejidad o(n*n)
*/

GList glist_sort(GList list, FComp fun);

#endif /*__GList_H__*/
