#include <stdlib.h>
#include "SList.h"

SList *slist_append(SList *list, int data)
{
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
	  return;
}

void  slist_foreach(SList *list, VisitorFuncInt visit, void *extra_data)
{
	  SList *node = list;

	  while (node != NULL) {
			visit(slist_data(node), extra_data);
			node = slist_next(node);
	  }
	  return;
}

//Ejercicio 2

ushort slist_has_next(SList *list)
{
	if(list) return slist_next(list) != NULL;
	return;
}

size_t slist_length(SList *list)
{
	size_t len;
	for(len = 0; list != NULL; len++, list = slist_next(list));
	return len;
}

SList *slist_concat(SList *list1, SList *list2)
{
	SList *node = list1;
	if (!list1) return list2;

	while (slist_next(node))
		node = slist_next(node);
	slist_next(node) = list2;

	return list1;
}

SList *slist_insert(SList *list, int data, size_t index)
{
	if (index > slist_length(list)) {
		puts("Indice incorrecto.");
		return;
	}

	SList *node, *newNode = malloc(sizeof(SList));
	slist_data(newNode) = data;
	slist_next(newNode) = NULL;
	
	if (!list || !index) {
		slist_next(newNode) = list;
		return newNode;
	}

	size_t idx;
	node = list;
	for(idx = 1 ; idx != index; idx++, node = slist_next(node));

	slist_next(newNode) = slist_next(node);
	slist_next(node) = newNode;

	return list;
}

SList *slist_remove(SList *list, size_t index)
{
	if (index >= slist_length(list)) {
		puts("Indice incorrecto.");
		return;
	}
	
	if (list == NULL) return list;
	
	SList *nTmp, *node;
	node = nTmp = list;
	size_t idx;

	if (index == 0) {
		list = slist_next(list);
		free(node);
		return list;
	}
	
	nTmp = slist_next(nTmp);
	for(idx = 1 ; idx != index && (slist_next(nTmp) != NULL); idx++){
		node = slist_next(node);
		nTmp = slist_next(nTmp);
	}

	slist_next(node) = slist_next(nTmp);
	free(nTmp);

	return list;
}

ushort slist_contains(SList *list, int data)
{
	if (!list) return 0;
	
	if(slist_data(list) == data) return 1;
	else slist_contains(slist_next(list), data);
}

int slist_index(SList *list, int data)
{
	int idx = -1, idxt = 0;
	while (list){
		if(slist_data(list) == data){
			idx = idxt;
			break;
		}
		idxt++;
		list = slist_next(list);
	}
	return idx;
}

SList *slist_intersect(SList *list1, SList *list2)
{
	SList *list3 = NULL, *node = list2;
	
	if(slist_length(node) == 1 && slist_contains(list1, slist_data(node))){
		list3 = slist_append(list3, slist_data(node));
		return list3;
	}
	size_t i = 0;
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

SList *slist_intersect_custom(SList *l1, SList *l2, FunComp f)
{
	SList *list3 = NULL, *node1 = l1, *node2 = l2;

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

SList *slist_sort(SList *list, comparar com)
{
	size_t i; 
	int *l = malloc(slist_length(list)*sizeof(slist_data(list)));
	SList *node = list;
	for(i = 0; i < slist_length(list); i++){
		l[i] = slist_data(node);
		node = slist_next(node);
	}

	qsort(l, slist_length(list), sizeof(int), com);
	
	node = list;
	for(i = 0; i < slist_length(list); i++){
		slist_data(node) = l[i];
		node = slist_next(node);
	}
	free(l);

	return list;
}