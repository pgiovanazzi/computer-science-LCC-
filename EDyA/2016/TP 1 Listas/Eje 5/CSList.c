#include <stdlib.h>
#include "CSList.h"

CSList cslist_append(CSList list, int data)
{
      CSList newNode = malloc(sizeof(CSNode));
      CSList node;
      cslist_data(newNode) = data;
      if (list == cslist_nil()) {
       	cslist_next(newNode) = newNode;
         return newNode;
      }
      node = list;
      while (cslist_next(node) != list) {
            node = cslist_next(node);
      }
      /* ahora 'node' apunta al ultimo nodo en la lista */
      cslist_next(node) = newNode;
      cslist_next(newNode) = list;
      return list;
}

CSList cslist_prepend(CSList list, int data)
{
      CSList newNode = malloc(sizeof(CSNode)), node = list;
     	if(list == cslist_nil()){
      	cslist_next(newNode) = newNode;
      	cslist_data(newNode) = data;
      	return newNode;
      }
      while(cslist_next(node) != list){
      	node = cslist_next(node);
      }
      cslist_data(newNode) = data;
      cslist_next(node) = newNode;
      cslist_next(newNode) = list;
      
      return newNode;
}

void  cslist_destroy(CSList list)
{
      CSList nodeToDelete, node = list;

      do{
         nodeToDelete = list;
         list = cslist_next(list);
         free(nodeToDelete);
      }while (list != node);
}

void  cslist_foreach(CSList list, VisitorFuncInt visit, void *extra_data)
{
      CSList node = list;

      do{
      	visit(cslist_data(node), extra_data);
         node = cslist_next(node);
      }while (node != list);
}

int cslist_length(CSList list){
	int count = 0;
	CSList node = list;
	if(list == cslist_nil()) return 0;
	do{
		node = cslist_next(node);
		count++;
	}while(node != list);
	return count;
}

CSList cslist_concat(CSList l1, CSList l2){
	if(l1){
		if(l2){
			CSList node = l1;
			while(cslist_next(node) != l1)
				node = cslist_next(node);
			cslist_next(node) = l2;
			node = l2;
			while(cslist_next(node) != l2)
				node = cslist_next(node);
			cslist_next(node) = l1;
		}
		return l1;
	}
	return l2;
}

CSList cslist_insert(CSList list, int data, int idx){
	int count = 1;
	CSList node = list, newNode = malloc(sizeof(CSNode));
	cslist_data(newNode) = data;
	if(idx < 0 || idx > cslist_length(list))
		return cslist_nil();
	if(idx == 0) return cslist_prepend(list,data);
	while(count != idx){
		node = cslist_next(node);
		count++;
	}
	cslist_next(newNode) = cslist_next(node);
	cslist_next(node) = newNode;
	return list;
}

CSList cslist_remove(CSList list, int idx){
	CSList node = list, nodePrev = list;
	int count = 0;
	if(idx < 0 || idx >= cslist_length(list))
		return cslist_nil();
	if(idx == 0){
		while(cslist_next(node) != list)
			node = cslist_next(node);
		cslist_next(node) = cslist_next(list);
		list = cslist_next(list);
		free(nodePrev);
		return list;
	}
	while(count != idx){
		node = cslist_next(node);
		if(++count == 1) continue;
		nodePrev = cslist_next(nodePrev);
	}
	cslist_next(nodePrev) = cslist_next(node);
	free(node);	
	return list;
}

int cslist_contains(CSList list, const int data){
	CSList node = list;
	do{
		if(data == cslist_data(node)) return 1;
		node = cslist_next(node);
	}while(node != list);
	return 0;
}

int cslist_index(CSList list, const int data){
	int idx = 0;
	CSList node = list;
	if(!cslist_contains(list,data)) return -1;
	do{
		if(data == cslist_data(node)) return idx;
		node = cslist_next(node);
		idx++;
	}while(node != list);
}

CSList cslist_intersect(CSList l1, CSList l2){
	CSList l3 = malloc(sizeof(CSNode)), node = l1;
	l3 = cslist_nil();

	do{
		if(cslist_contains(l2,cslist_data(node)))
			l3 = cslist_append(l3,cslist_data(node));
		node = cslist_next(node);
	}while(node != l1);
	/* funciona mal, teoricamente quita los elementos redundantes
	CSList nodePrev = l3;
	node = l3;
	do{
		node = cslist_next(nodePrev);
		if(cslist_contains(node,cslist_data(nodePrev)))
			node = cslist_remove(node, cslist_index(node,cslist_data(nodePrev)));
		nodePrev = cslist_next(nodePrev);
	}while(nodePrev != l3);
	*/
	return l3;
}

CSList cslist_intersect_custom(CSList l1, CSList l2, FComp fun){
	CSList l3 = malloc(sizeof(CSNode)), node1 = l1, node2 = l2;
	l3 = cslist_nil();
	do{
		node2 = l2;
		do{
			if(!fun(&cslist_data(node1),&cslist_data(node2)))
				l3 = cslist_append(l3,cslist_data(node1));
			node2 = cslist_next(node2);
		}while(node2 != l2);
		node1 = cslist_next(node1);	
	}while(node1 != l1);
	return l3;
}

CSList cslist_sort(CSList list, FComp fun){
	CSList node1 = list, node2 = list;
	int tmp;
	do{
		node2 = cslist_next(node1);
		while(node2 != list){
			if(fun(&cslist_data(node1),&cslist_data(node2)) > 0){
				tmp = cslist_data(node1);
				cslist_data(node1) = cslist_data(node2);
				cslist_data(node2) = tmp;
			}
			node2 = cslist_next(node2);
		}
		node1 = cslist_next(node1);
	}while(node1 != list);
	
	return list;
}

