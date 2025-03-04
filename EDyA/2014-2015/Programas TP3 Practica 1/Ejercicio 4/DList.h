#ifndef __DLIST_h__
#define __DLIST_h__

typedef void (*VisitorFuncInt) (int data, void *extra_data);

typedef enum {
	DLIST_TRAVERSAL_ORDER_FORWARD,
	DLIST_TRAVERSAL_ORDER_REWARD
} DListTraversalOrder;

/**
 * Los campos son privados, y no deberian ser accedidos
 * desde el código cliente.
 */

 typedef struct _DLNode{
 	int data;
 	struct _DLNode *next;
 	struct _DLNode *back;
 }DList;

#define dlist_data(l)       (l)->data
#define dlist_next(l)       (l)->next
#define dlist_back(l)       (l)->back

/**
 * Agrega un elemento al final de la lista, en complejidad O(n).
 *
 * Nota: una lista vacia se representa con un (DList *) NULL.
 */
DList *dlist_append(DList *list, int data);

/**
 * Agrega un elemento al inicio de la lista, en complejidad O(1).
 *
 * Nota: una lista vacia se representa con un (DList *) NULL.
 */
DList *dlist_prepend(DList *list, int data);

/**
 * Destruccion de la lista.
 */
void  dlist_destroy(DList *list);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void  dlist_foreach(DList *list, VisitorFuncInt visit, void *extra_data, DListTraversalOrder n);

//si un nodo tiene siguiente elemento.
int dlist_has_next(DList *list);

//si un nodo tiene anterior elemento.
int dlist_has_back(DList *list);

//la longitud de una lista.
int dlist_length(DList *list);

//devuelva la concatenaci ́on de dos listas.
DList *dlist_concat(DList *list1, DList *list2);

//inserta un dato en una lista en una posición arbitraria.
DList *dlist_insert(DList *list, int data, unsigned int index);

//borra de una lista un dato apuntado en una posici ́n arbitraria.
DList *dlist_remove(DList *list, unsigned int index);

//que diga si un elemento est ́ en una lista dada.
int dlist_contains(DList *list, int data);

//devuelva la posición del elemento data si el mismo está en la lista list.
unsigned int dList_index(DList *list, const int data);

//devuelva una nueva lista con los elementos comunes.
DList *dlist_intersect(DList *list1, DList *list2);

//trabaja como la anterior pero recibe un parámetro extra que es un puntero a una función de 
//comparación que permite definir la noción de igualdad a ser usada al comparar elementos por igualdad.
typedef int (*FunComp)(int a, int b);
DList *dlist_intersect_custom(DList *l1, DList *l2, FunComp f);

//ordena una lista de acuerdo al criterio dado por la funcón de comparación pasada por parámetro
typedef int (*comparar)(const void *, const void *);
DList *dlist_sort(DList *list, comparar com);

#endif /* __DLIST_H__ */