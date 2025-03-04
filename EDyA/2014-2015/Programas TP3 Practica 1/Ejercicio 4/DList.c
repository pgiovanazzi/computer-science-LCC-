#include <stdlib.h>
#include "DList.h"

DList *dlist_append(DList *list, int data){
	DList *newNode = malloc(sizeof(DList));
	DList *node;
	dlist_data(newNode) = data;
	dlist_next(newNode) = NULL;
	dlist_back(newNode) = NULL;

	if (list == NULL) {
		return newNode;
	}
	node = list;
	while (dlist_next(node) != NULL) {
		node = dlist_next(node);
	}
	
	/* ahora 'node' apunta al ultimo nodo en la lista */
	dlist_next(node) = newNode;
	dlist_back(newNode) = node;
	return list;
}

DList *dlist_prepend(DList *list, int data){
	DList *newNode = malloc(sizeof(DList));
	dlist_data(newNode) = data;
	dlist_next(newNode) = NULL;
	dlist_back(newNode) = NULL;
	if(list == NULL)
		return newNode;
	dlist_next(newNode) = list;
	dlist_back(list) = newNode;
	return newNode;
}

void  dlist_destroy(DList *list){
	DList *nodeToDelete;

	while (list != NULL){
		nodeToDelete = list;
		list = dlist_next(list);
		free(nodeToDelete);
	}
}

void  dlist_foreach(DList *list, VisitorFuncInt visit, void *extra_data, DListTraversalOrder n){
	DList *node = list;

	if (n == 0){
		while (node != NULL){
			visit(dlist_data(node), extra_data);
			node = dlist_next(node);
		}
	}
	else{
		while (dlist_next(node) != NULL)
			node = dlist_next(node);
		while(node != NULL){
			visit(dlist(data), extra_data);
			node = dlist_back(node);
		}
	}
}

//Ejercicio 2

int dlist_has_next(DList *list){
	if(dlist_next(list) != NULL)
		return 1;
	else
		return 0;
}

int dlist_has_back(DList *list){
	if(dlist_back(list) != NULL)
		return 1;
	else
		return 0;
}

int dlist_length(DList *list){
	int cont = 0;
	DList *node = list;
	while (node != NULL){
		cont++;
		node = dlist_next(node);
	}
	return cont;
}

DList *dlist_concat(DList *list1, DList *list2){
	DList *node = list1;
	if (list1 == NULL)
		return list2;
	else
		while (dlist_next(node) != NULL)
			node = dlist_next(node);
		dlist_next(node) = list2;

	return list1;
}

DList *dlist_insert(DList *list, int data, unsigned int index){
	if (index < 0 || index > dlist_length(list)){
		puts("Indice incorrecto.");
		return;
	}

	DList *node1, *newNode = malloc(sizeof(DList));
	dlist_data(newNode) = data;
	dlist_next(newNode) = NULL;
	dlist_back(newNode) = NULL;
	
	if (list == NULL)
		return newNode;
	if (index == 0)
		return dlist_prepend(list, data);
	if (index == dlist_length(list))
		return dlist_append(list, data);
	else{
		int i = 1;
		node1 = list;
		while (dlist_next(node1) != NULL && i != index){
				node1 = dlist_next(node1);
				i++;
		}
	
		dlist_next(newNode) =  dlist_next(node1);
		dlist_next(node1) = newNode;
		dlist_back(newNode) = node1;
		return list;
	}
}

DList *dlist_remove(DList *list, unsigned int index){
	if (index < 0 || index > dlist_length(list)){
		puts("Indice incorrecto.");
		return;
	}
	
	DList *node = list;
	if (index == 0){
		if (dlist_next(list) == NULL){
			list = NULL;
			free(list);
			return list;
		}
		list = dlist_next(list);
		node = NULL;
		free(node);
	}
	else{
		int i = 1;
		while (dlist_next(node) != NULL && i != index){
			node = dlist_next(node);
			i++;
		}
		dlist_next(node) = dlist_next(dlist_next(node));
		if (dlist_next(node) == NULL){
			node = NULL;
			free(node);
			return list;
		}
		node = dlist_next(node);
		node = NULL;
		free(node);
	}
	return list;
}

int dlist_contains(DList *list, int data){
	DList *node = list;
	if (dlist_length(node) == 1 && dlist_data(node) == data)
		return 1;
	
	while (dlist_next(node) != NULL){
		if (dlist_data(node) == data)
			return 1;
		node = dlist_next(node);
	}
	
	if (dlist_data(node) == data)
		return 1;
	
	return 0;
}

unsigned int dlist_index(DList *list, const int data){
	int i = 0;
	DList *node = list;
	
	if (dlist_length(node) == 1 && dlist_data(node) == data)
		return i;
	
	while (dlist_next(node) != NULL){
		if(dlist_data(node) == data)
			return i;
		node = dlist_next(node);
		i++;
	}
	
	if(dlist_data(node) == data)
		return i;
}

DList *dlist_intersect(DList *list1, DList *list2){
	DList *list3 = NULL, *node = list2;
	
	if(dlist_length(node) == 1 && dlist_contains(list1, dlist_data(node))){
		list3 = dlist_append(list3, dlist_data(node));
		return list3;
	}
	int i = 0;
	while(dlist_next(node) != NULL){
		if (dlist_contains(list1, dlist_data(node))){
			list3 = dlist_append(list3, dlist_data(node));
			dlist_remove(node, i--);
		}
		node = dlist_next(node);
		i++;
	}
	
	if (dlist_contains(list1, dlist_data(node)))
		list3 = dlist_append(list3, dlist_data(node));
	
	return list3;
}

typedef int (*FunComp)(int a, int b);

DList *dlist_intersect_custom(DList *l1, DList *l2, FunComp f){
	DList *list3 = NULL, *node1 = l1, *node2 = l2;
	int i = 0;

	if ((dlist_length(node1) == 1 || dlist_length(node2) == 1) && (f(dlist_data(node1), dlist_data(node2)) == 0)){
		list3 = dlist_append(list3, dlist_data(node1));
		return list3;
	}

	while(dlist_next(node1) != NULL){
		if (f(dlist_data(node1), dlist_data(node2)) == 0)
			list3 = dlist_append(list3, dlist_data(node1));
		node1 = dlist_next(node1);
		node2 = dlist_next(node2);
	}

	if (f(dlist_data(node1), dlist_data(node2)) == 0)
		list3 = dlist_append(list3, dlist_data(node1));

	return list3;
}

/*int compare(const void *a, const void *b){
	return ( *(int*)a - *(int*)b );
}*/

typedef int (*comparar)(const void *, const void *);

DList *dlist_sort(DList *list, comparar com){
	int i, *l = malloc(dlist_length(list)*sizeof(int));
	DList *node = list;
	for(i = 0; i < dlist_length(list); i++){
		*(l+i) = dlist_data(node);
		node = dlist_next(node);
	}

	qsort(l, dlist_length(list), sizeof(int), com);
	
	node = list;
	for(i = 0; i < dlist_length(list); i++){
		dlist_data(node) = *(l+i);
		node = dlist_next(node);
	}
	
	return list;
}