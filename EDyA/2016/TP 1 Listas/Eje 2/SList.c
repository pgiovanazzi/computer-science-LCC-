#include <stdlib.h>
#include "SList.h"

SList slist_append(SList list, int data)
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

SList slist_prepend(SList list, int data)
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

void  slist_foreach(SList list, VisitorFuncInt visit, void *extra_data)
{
      SList node = list;

      while (node != slist_nil()) {
            visit(slist_data(node), extra_data);
            node = slist_next(node);
      }
}

int slist_has_next(SList node){
	return slist_next(node) != slist_nil();
}

int slist_length(SList list){
	int count = 0;
	SList node = list;
	while(node != slist_nil()){
		node = slist_next(node);
		count++;
	}
	return count;
}

SList slist_concat(SList l1, SList l2){
	if(l1){
		SList node = l1;
		while(slist_has_next(node))
			node = slist_next(node);
		slist_next(node) = l2;
		return l1;
	}
	return l2;
}

SList slist_insert(SList list, int data, int idx){
	int count = 1;
	SList node = list, newNode = malloc(sizeof(SNode));
	slist_data(newNode) = data;
	if(idx < 0 || idx > slist_length(list))
		return slist_nil();
	if(idx == 0) return slist_prepend(list,data);
	while(count != idx){
		node = slist_next(node);
		count++;
	}
	slist_next(newNode) = slist_next(node);
	slist_next(node) = newNode;
	return list;
}


SList slist_remove(SList list, int idx){
	SList node = list, nodePrev = list;
	int count = 0;
	if(idx < 0 || idx >= slist_length(list))
		return slist_nil();
	if(idx == 0){
		list = slist_next(list);
		free(nodePrev);
		return list;
	}
	while(count != idx){
		node = slist_next(node);
		if(++count == 1) continue;
		nodePrev = slist_next(nodePrev);
	}
	slist_next(nodePrev) = slist_next(node);
	free(node);

	return list;
}

int slist_contains(SList list, const int data){
	SList node = list;
	while(node != slist_nil()){
		if(data == slist_data(node)) return 1;
		node = slist_next(node);
	}
	return 0;
}

int slist_index(SList list, const int data){
	int idx = 0;
	SList node = list;
	if(!slist_contains(list,data)) return -1;
	while(node != slist_nil()){
		if(data == slist_data(node)) return idx;
		node = slist_next(node);
		idx++;
	}
}

SList RepetElemDelet(SList list){
  SList node = list, l3 = slist_nil();
  l3 = slist_append(l3,slist_data(node));
  node = slist_next(node);
  while (node) {
    if (slist_contains(l3,slist_data(node))){
      node = slist_next(node);
      continue;
    }
    l3 = slist_append(l3,slist_data(node));
    node = slist_next(node);
  }

  return l3;
}

SList slist_intersect(SList l1, SList l2){
	SList l3 = malloc(sizeof(SNode)), node = l1;
	l3 = slist_nil();

	while(node != slist_nil()){
		if(slist_contains(l2,slist_data(node)))
			l3 = slist_append(l3,slist_data(node));
		node = slist_next(node);
	}

	l3 = RepetElemDelet(l3);

	return l3;
}

SList slist_intersect_custom(SList l1, SList l2, FComp fun){
	SList l3 = malloc(sizeof(SNode)), node1 = l1, node2 = l2;
	l3 = slist_nil();
	while(node1 != slist_nil()){
		while(node2 != slist_nil()){
			if(!fun(&slist_data(node1),&slist_data(node2)))
				l3 = slist_append(l3,slist_data(node1));
			node2 = slist_next(node2);
		}
		node1 = slist_next(node1);
	}
	return l3;
}

SList slist_sort(SList list, FComp fun){
	SList node1 = list, node2 = list;
	int tmp;
	while(node1 != slist_nil()){
		node2 = slist_next(node1);
		while(node2 != slist_nil()){
			if(fun(&slist_data(node1),&slist_data(node2)) > 0){
				tmp = slist_data(node1);
				slist_data(node1) = slist_data(node2);
				slist_data(node2) = tmp;
			}
			node2 = slist_next(node2);
		}
		node1 = slist_next(node1);
	}

	return list;
}
