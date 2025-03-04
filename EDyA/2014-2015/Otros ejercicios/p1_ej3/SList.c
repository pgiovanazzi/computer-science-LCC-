#include <stdlib.h>
#include "SList.h"

SList slist_append(SList list, void *data)
{
      SList newNode = malloc(sizeof(SNode));
      SList node;
      slist_data(newNode) = data;
      slist_next(newNode) = NULL;
      if (list == slist_nil()) {
         return newNode;
      }
      node = list;
      while (slist_next(node) != slist_nil()) {
            node = slist_next(node);
      }
      /* ahora 'node' apunta al ultimo nodo en la lista */
      slist_next(node) = newNode;
      return list;
}

SList slist_prepend(SList list, void *data)
{
      SList newNode = malloc(sizeof(SNode));
      slist_next(newNode) = list;
      slist_data(newNode) = data;
      return newNode;
}

void  slist_destroy(SList list)
{
      SList nodeToDelete;

      while (list != slist_nil()) {
            nodeToDelete = list;
            list = slist_next(list);
            free(nodeToDelete);
      }
}

void  slist_foreach(SList list, VisitorFunc visit, void *extra_data)
{
      SList node = list;

      while (node != slist_nil()) {
            visit(slist_data(node), extra_data);
            node = slist_next(node);
      }
}
