#include<stdlib.h>
#include "DList.h"

DList dlist_append(DList list, int data)
{
      DList newNode = malloc(sizeof(DNode));
      DList node;
      dlist_data(newNode) = data;
      dlist_next(newNode) = NULL;
      dlist_prev(newNode) = NULL;
      if (list == dlist_nil()) {
         return newNode;
      }
      node = list;
      while (dlist_next(node) != dlist_nil()) {
            node = dlist_next(node);
      }
      /* ahora 'node' apunta al ultimo nodo en la lista */
      dlist_next(node) = newNode;
      dlist_prev(newNode) = node;
      return list;
}

DList dlist_prepend(DList list, int data)
{
      DList newNode = malloc(sizeof(DNode));
      if(list)
         dlist_prev(list) =  newNode;
      dlist_next(newNode) = list;
      dlist_prev(newNode) = NULL;
      dlist_data(newNode) = data;
      return newNode;
}

void  dlist_destroy(DList list)
{
      DList nodeToDelete;

      while (list != dlist_nil()) {
            nodeToDelete = list;
            list = dlist_next(list);
            free(nodeToDelete);
      }
}

void  dlist_foreach(DList list, VisitorFuncInt visit, void *extra_data, DListTraversalOrder order)
{
      DList node = list;
		
		if(!order)
      	while (node != dlist_nil()) {
         	   visit(dlist_data(node), extra_data);
         	   node = dlist_next(node);
      	}
      else{
			 while(dlist_next(node) != dlist_nil())
			 	node = dlist_next(node);
			 while(node != dlist_nil()){
			 	visit(dlist_data(node),extra_data);
			 	node = dlist_prev(node);
			 }
      }
}

int dlist_has_next(DList node){
   return dlist_next(node) != dlist_nil();
}

int dlist_has_prev(DList node){
   return dlist_prev(node) != dlist_nil();
}

int dlist_length(DList list){
   int count = 0;
   DList node = list;
   while(node != dlist_nil()){
      node = dlist_next(node);
      count++;
   }
   return count;
}

DList dlist_concat(DList l1, DList l2){
	if(l1){
		DList node = l1;
		while(dlist_has_next(node))
			node = dlist_next(node);
		dlist_next(node) = l2;
		if(l2)
			dlist_prev(l2) = node;
		return l1;
	}
	return l2;
}

DList dlist_insert(DList list, int data, int idx){
	int count = 1;
	DList node = list, newNode = malloc(sizeof(DNode));
	dlist_data(newNode) = data;
	if(idx < 0 || idx > dlist_length(list))
		return dlist_nil();
	if(idx == 0){
		dlist_next(newNode) = list;
		dlist_prev(list) = newNode;
		dlist_prev(newNode) = dlist_nil();
		return newNode;
	}
	while(count != idx){
		node = dlist_next(node);
		count++;
	}
	dlist_next(newNode) = dlist_next(node);
	dlist_prev(newNode) = node;
	if(dlist_next(node))
		dlist_prev(dlist_next(node)) = newNode;
	dlist_next(node) = newNode;
	return list;
}

DList dlist_remove(DList list, int idx){
	DList node = list, nodePrev = list;
	int count = 0;
	if(idx < 0 || idx >= dlist_length(list))
		return dlist_nil();
	if(idx == 0){
		list = dlist_next(list);
		dlist_prev(list) = dlist_nil();
		free(nodePrev);
		return list;
	}
	while(count != idx){
		node = dlist_next(node);
		if(++count == 1) continue;
		nodePrev = dlist_next(nodePrev);
	}
	dlist_next(nodePrev) = dlist_next(node);
	if(dlist_next(node))
		dlist_prev(dlist_next(node)) = nodePrev;
	free(node);
	return list;
}

int dlist_contains(DList list, const int data){
	DList node = list;
	while(node != dlist_nil()){
		if(data == dlist_data(node)) return 1;
		node = dlist_next(node);
	}
	return 0;
}

int dlist_index(DList list, const int data){
	int idx = 0;
	DList node = list;
	if(!dlist_contains(list,data)) return -1;
	while(node != dlist_nil()){
		if(data == dlist_data(node)) return idx;
		node = dlist_next(node);
		idx++;
	}
}

DList dlist_intersect(DList l1, DList l2){
	DList l3 = malloc(sizeof(DNode)), node = l1;
	l3 = dlist_nil();

	while(node != dlist_nil()){
		if(dlist_contains(l2,dlist_data(node)))
			l3 = dlist_append(l3,dlist_data(node));
		node = dlist_next(node);
	}
	
	DList nodePrev = l3;
	node = l3;
	while(nodePrev != dlist_nil()){
		node = dlist_next(nodePrev);
		if(dlist_contains(node,dlist_data(nodePrev)))
			dlist_remove(node, dlist_index(node,dlist_data(nodePrev)));
		nodePrev = dlist_next(nodePrev);
	}
	
	return l3;
}

DList dlist_intersect_custom(DList l1, DList l2, FComp fun){
	DList l3 = malloc(sizeof(DNode)), node1 = l1, node2 = l2;
	l3 = dlist_nil();
	while(node1 != dlist_nil()){
		node2 = l2;
		while(node2 != dlist_nil()){
			if(!fun(&dlist_data(node1),&dlist_data(node2)))
				l3 = dlist_append(l3,dlist_data(node1));
			node2 = dlist_next(node2);
		}
		node1 = dlist_next(node1);
	}
	return l3;
}

DList dlist_sort(DList list, FComp fun){
	DList node1 = list, node2 = list;
	int tmp;
	while(node1 != dlist_nil()){
		node2 = dlist_next(node1);
		while(node2 != dlist_nil()){
			if(fun(&dlist_data(node1),&dlist_data(node2)) > 0){
				tmp = dlist_data(node1);
				dlist_data(node1) = dlist_data(node2);
				dlist_data(node2) = tmp;
			}
			node2 = dlist_next(node2);
		}
		node1 = dlist_next(node1);
	}
	
	return list;
}












