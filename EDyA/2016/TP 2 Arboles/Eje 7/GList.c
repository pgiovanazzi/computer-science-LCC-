#include <stdlib.h>
#include "GList.h"

GList glist_append(GList list, void *data)
{
      GList newNode = malloc(sizeof(GNode));
      GList node;
      glist_data(newNode) = data;
      glist_next(newNode) = NULL;
      if (list == glist_nil()) {
         return newNode;
      }
      node = list;
      while (glist_next(node) != glist_nil()) {
            node = glist_next(node);
      }
      /* ahora 'node' apunta al ultimo nodo en la lista */
      glist_next(node) = newNode;
      return list;
}

GList glist_prepend(GList list, void *data)
{
      GList newNode = malloc(sizeof(GNode));
      glist_next(newNode) = list;
      glist_data(newNode) = data;
      return newNode;
}

void  glist_destroy(GList list)
{
      GList nodeToDelete;

      while (list != glist_nil()) {
            nodeToDelete = list;
            list = glist_next(list);
            free(nodeToDelete);
      }
}

void  glist_foreach(GList list, VisitorFuncInt visit, void *extra_data)
{
      GList node = list;

      while (node != glist_nil()) {
            visit(glist_data(node), extra_data);
            node = glist_next(node);
      }
}

int glist_has_next(GList node){
	return glist_next(node) != glist_nil();
}

int glist_length(GList list){
	int count = 0;
	GList node = list;
	while(node != glist_nil()){
		node = glist_next(node);
		count++;
	}
	return count;
}

GList glist_concat(GList l1, GList l2){
	if(l1){
		GList node = l1;
		while(glist_has_next(node))
			node = glist_next(node);
		glist_next(node) = l2;
		return l1;
	}
	return l2;
}

GList glist_insert(GList list, void *data, int idx){
	int count = 1;
	GList node = list, newNode = malloc(sizeof(GNode));
	glist_data(newNode) = data;
	if(idx < 0 || idx > glist_length(list))
		return glist_nil();
	if(idx == 0) return glist_prepend(list,data);
	while(count != idx){
		node = glist_next(node);
		count++;
	}
	glist_next(newNode) = glist_next(node);
	glist_next(node) = newNode;
	return list;
}


GList glist_remove(GList list, int idx){
	GList node = list, nodePrev = list;
	int count = 0;
	if(idx < 0 || idx >= glist_length(list))
		return glist_nil();
	if(idx == 0){
		list = glist_next(list);
		free(nodePrev);
		return list;
	}
	while(count != idx){
		node = glist_next(node);
		if(++count == 1) continue;
		nodePrev = glist_next(nodePrev);
	}
	glist_next(nodePrev) = glist_next(node);
	free(node);

	return list;
}

int glist_contains(GList list, const void *data){
	GList node = list;
	while(node != glist_nil()){
		if(*(int*)data == *(int*)glist_data(node)) return 1;
		node = glist_next(node);
	}
	return 0;
}

int glist_index(GList list, const void *data){
	int idx = 0;
	GList node = list;
	if(!glist_contains(list,data)) return -1;
	while(node != glist_nil()){
		if(data == glist_data(node)) return idx;
		node = glist_next(node);
		idx++;
	}
}

GList glist_intersect(GList l1, GList l2){
	GList l3 = malloc(sizeof(GNode)), node = l1;
	l3 = glist_nil();

	while(node != glist_nil()){
		if(glist_contains(l2,glist_data(node)))
			l3 = glist_append(l3,glist_data(node));
		node = glist_next(node);
	}

	GList nodePrev = l3;
	node = l3;
	while(nodePrev != glist_nil()){
		node = glist_next(nodePrev);
		if(glist_contains(node,glist_data(nodePrev)))
			glist_remove(node, glist_index(node,glist_data(nodePrev)));
		nodePrev = glist_next(nodePrev);
	}

	return l3;
}

GList glist_intersect_custom(GList l1, GList l2, FComp fun){
	GList l3 = malloc(sizeof(GNode)), node1 = l1, node2 = l2;
	l3 = glist_nil();
	while(node1 != glist_nil()){
		while(node2 != glist_nil()){
			if(!fun(glist_data(node1),glist_data(node2)))
				l3 = glist_append(l3,glist_data(node1));
			node2 = glist_next(node2);
		}
		node1 = glist_next(node1);
	}
	return l3;
}

GList glist_sort(GList list, FComp fun){
	GList node1 = list, node2 = list;
	void *tmp;
	while(node1 != glist_nil()){
		node2 = glist_next(node1);
		while(node2 != glist_nil()){
			if(fun(glist_data(node1),glist_data(node2)) > 0){
				tmp = glist_data(node1);
				glist_data(node1) = glist_data(node2);
				glist_data(node2) = tmp;
			}
			node2 = glist_next(node2);
		}
		node1 = glist_next(node1);
	}

	return list;
}
