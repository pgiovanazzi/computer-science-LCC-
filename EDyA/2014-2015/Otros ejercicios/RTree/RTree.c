#include "RTree.h"
#include <stdio.h>
#include <stdlib.h>

SList *slist_append(SList *list, void* data) {
  SList *newNode = malloc(sizeof(SList));
  SList *node;
  slist_data(newNode) = data;
  slist_next(newNode) = NULL;
  if (list == NULL) {
    return newNode;
  }
  node = list;
  while (slist_next(node) != NULL) {
    node = slist_next(node);
  }
  /* ahora 'node' apunta al ultimo nodo en la lista */
  slist_next(node) = newNode;
  return list;
}


/*
 * Crea un nodo nuevo que contiene el dato 
 *  pasado como argumento, y no tiene hijos 
 */
RTree* createNode(void* data) {
  RTree* node = (RTree*) malloc(sizeof(RTree));
  node->data = data;
  node->children = NULL;
  return node;
}


/*
 * Agrega un arbol a la lista de hijos de otro
 */
void rtreeAddChild(RTree* parent, RTree* child) {
  parent->children = slist_append(parent->children, child);
  return;
}

/*
 * Aplica una funcion a todos los datos contenidos en un arbol
 */
void  rtreeForeach(RTree* node, rtree_visitor_func func, void* extra_data) {
  if (NULL == node)
    return;
 
  func(node->data, extra_data);

  void *p = node->children;
  while (NULL != p) {
    rtreeForeach(((SList*)p)->data, func, extra_data);
    p = ((SList*)p)->next;
  }

  return;
 }


