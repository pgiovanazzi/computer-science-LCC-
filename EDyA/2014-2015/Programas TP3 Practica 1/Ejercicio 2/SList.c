#include <stdlib.h>
#include "SList.h"

SList *slist_append(SList *list, int data){
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

SList *slist_prepend(SList *list, int data)
{
      SList *newNode = malloc(sizeof(SList));
      slist_next(newNode) = list;
      slist_data(newNode) = data;
      return newNode;
}

void  slist_destroy(SList *list)
{
      SList *nodeToDelete;

      while (list != NULL) {
            nodeToDelete = list;
            list = slist_next(list);
            free(nodeToDelete);
      }
}

void  slist_foreach(SList *list, VisitorFuncInt visit, void *extra_data)
{
      SList *node = list;

      while (node != NULL) {
            visit(slist_data(node), extra_data);
            node = slist_next(node);
      }
}

//Ejercicio 2

int slist_has_next(SList *list){
	if(slist_next(list) != NULL)
		return 1;
	else
		return 0;
}

int slist_length(SList *list){
	int cont = 0;
	SList *node = list;
	while (node != NULL){
		cont++;
		node = slist_next(node);
	}
	return cont;
}

SList *slist_concat(SList *list1, SList *list2){
	SList *node = list1;
	if (list1 == NULL)
		return list2;
	else
		while (slist_next(node) != NULL)
			node = slist_next(node);
		slist_next(node) = list2;

	return list1;
}

SList *slist_insert(SList *list, int data, unsigned int index){
	if (index < 0 || index >= slist_length(list)){
		puts("Indice incorrecto.");
		return;
	}

	SList *node1, *newNode = malloc(sizeof(SList));
	slist_data(newNode) = data;
	slist_next(newNode) = NULL;
	
	if (list == NULL)
		return newNode;
	if (index == 0)
		return slist_prepend(list, data);
	if (index == slist_length(list))
		return slist_append(list, data);
	else{
		int i = 1;
		node1 = list;
		while (slist_next(node1) != NULL && i != index){
				node1 = slist_next(node1);
				i++;
		}
	
		slist_next(newNode) =  slist_next(node1);
		slist_next(node1) = newNode;
		return list;
	}
}

SList *slist_remove(SList *list, unsigned int index){
	if (index < 0 || index >= slist_length(list)){
		puts("Indice incorrecto.");
		return;
	}
	
	SList *node = list;
	if (index == 0){
		if (slist_next(list) == NULL){
			list = NULL;
			free(list);
			return list;
		}
		list = slist_next(list);
		node = NULL;
		free(node);
	}
	else{
		int i = 1;
		while (slist_next(node) != NULL && i != index){
			node = slist_next(node);
			i++;
		}
		slist_next(node) = slist_next(slist_next(node));
		if (slist_next(node) == NULL){
			node = NULL;
			free(node);
			return list;
		}
		node = slist_next(node);
		node = NULL;
		free(node);
	}
	return list;
}

int slist_contains(SList *list, int data){
	SList *node = list;
	if (slist_length(node) == 1 && slist_data(node) == data)
		return 1;
	
	while (slist_next(node) != NULL){
		if (slist_data(node) == data)
			return 1;
		node = slist_next(node);
	}
	
	if (slist_data(node) == data)
		return 1;
	
	return 0;
}

unsigned int slist_index(SList *list, const int data){
	int i = 0;
	SList *node = list;
	if(list == NULL)
		return -1;
	while (slist_next(node) != NULL && slist_data(node) != data){
		node = slist_next(node);
		i++;
	}
	
	if(slist_data(node) == data)
		return i;
	
	return -1;
}

SList *slist_intersect(SList *list1, SList *list2){
	SList *list3 = NULL, *node = list2;
	
	if(slist_length(node) == 1 && slist_contains(list1, slist_data(node))){
		list3 = slist_append(list3, slist_data(node));
		return list3;
	}
	int i = 0;
	while(slist_next(node) != NULL){
		if (slist_contains(list1, slist_data(node))){
			list3 = slist_append(list3, slist_data(node));
			slist_remove(node, i--);
		}
		node = slist_next(node);
		i++;
	}
	
	if (slist_contains(list1, slist_data(node)))
		list3 = slist_append(list3, slist_data(node));
	
	return list3;
}

typedef int (*FunComp)(int a, int b);

SList *slist_intersect_custom(SList *l1, SList *l2, FunComp f){
	SList *list3 = NULL, *node1 = l1, *node2 = l2;
	int i = 0;

	if ((slist_length(node1) == 1 || slist_length(node2) == 1) && (f(slist_data(node1), slist_data(node2)) == 0)){
		list3 = slist_append(list3, slist_data(node1));
		return list3;
	}

	while(slist_next(node1) != NULL){
		if (f(slist_data(node1), slist_data(node2)) == 0)
			list3 = slist_append(list3, slist_data(node1));
		node1 = slist_next(node1);
		node2 = slist_next(node2);
	}

	if (f(slist_data(node1), slist_data(node2)) == 0)
		list3 = slist_append(list3, slist_data(node1));

	return list3;
}

/*int compare(const void *a, const void *b){
	return ( *(int*)a - *(int*)b );
}*/

typedef int (*comparar)(const void *, const void *);

SList *slist_sort(SList *list, comparar com){
	int i, *l = malloc(slist_length(list)*sizeof(int));
	SList *node = list;
	for(i = 0; i < slist_length(list); i++){
		*(l+i) = slist_data(node);
		node = slist_next(node);
	}

	qsort(l, slist_length(list), sizeof(int), com);
	
	node = list;
	for(i = 0; i < slist_length(list); i++){
		slist_data(node) = *(l+i);
		node = slist_next(node);
	}
	
	return list;
}