#ifndef __RTree_H__
#define __RTree_H__
#include "GList.h"

typedef void (*rtree_visitor_func)(void* data, void* extra_data);

typedef struct _RTNode{
  void *data;
  GList children;
} RTNode;

typedef RTNode *RTree;

#define rtree_data(t)       (t)->data
#define rtree_children(t)   (t)->children
#define rtree_nil()         NULL

        /* Prototypes */
/*
 *  Crea un nodo nuevo rose tree pasando el dato y sin hijos
 */
RTree rtree_createNode(void *data);
/*
 *  Agrega un arbol rose tree a la lista de hijos de otro
 */
void rtree_addChild(RTree rt, RTree childre);
/*
 * Aplica una funcion a todos los datos contenidos en un arbol
 */
void rtree_foreach(RTree rt, rtree_visitor_func visit, void *extra_data);

#endif /*__RTree_H__*/
