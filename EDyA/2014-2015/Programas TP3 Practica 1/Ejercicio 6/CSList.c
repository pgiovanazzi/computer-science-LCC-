#include <stdlib.h>
#include "CSList.h"


CSList *cslist_append(CSList *list, int data){
	CSList *newNode = malloc(sizeof(CSList));
	CSList *node;
	cslist_data(newNode) = data;
	cslist_next(newNode) = list;
	if (list == NULL) {
		return newNode;
	}
	node = list;
	while (cslist_next(node) != list){
		node = cslist_next(node);
	}
	/* ahora 'node' apunta al ultimo nodo en la lista */
	cslist_next(node) = newNode;
	return list;
}

CSList *cslist_prepend(CSList *list, int data){
	CSList *node = list,*newNode = malloc(sizeof(CSList));
	cslist_next(newNode) = list;
	cslist_data(newNode) = data;
	while(cslist_next(node) != list)
		node = cslist_next(node);
	cslist_next(node) = newNode;
	return newNode;
}

void  cslist_destroy(CSList *list){
	  CSList *nodeToDelete;

	  while (list != NULL) {
			nodeToDelete = list;
			list = cslist_next(list);
			free(nodeToDelete);
	  }
}

void  cslist_foreach(CSList *list, VisitorFuncInt visit, void *extra_data){
	  CSList *node = list;

	  while (cslist_next(node) != list) {
			visit(slist_data(node), extra_data);
			node = cslist_next(node);
	  }
}

//Ejercicio 2

int cslist_has_next(CSList *list){
	if(cslist_next(list) != NULL)
		return 1;
	else
		return 0;
}

int cslist_length(CSList *list){
	int cont = 0;
	CSList *node = list;
	while (cslist_next(node) != list){
		cont++;
		node = cslist_next(node);
	}
	return cont;
}

CSList *cslist_concat(CSList *list1, CSList *list2){
	CSList *node1 = list1, *node2;
	if (list1 == NULL)
		return list2;
	else
		while (cslist_next(node1) != list1)
			node1 = cslist_next(node1);
		cslist_next(node1) = list2;
		while (cslist_next(node2) != list2)
			node1 = cslist_next(node2);
		cslist_next(node2) = list1;
		
	return list1;
}

CSList *cslist_insert(CSList *list, int data, unsigned int index){
	if (index < 0 || index >= slist_length(list)){
		puts("Indice incorrecto.");
		return;
	}

	CSList *node1 =list, *newNode = malloc(sizeof(SList));

	cslist_data(newNode) = data;
	cslist_next(newNode) = NULL;
	
	if (list == NULL){
		cslist_next(newNode) = newNode;
		return newNode;
	}
	if (index == 0){
		cslist_next(newNode) = list;
		while (cslist_next(node1) != list)
			node1 = cslist_next(node1);
		cslist_next(ndoe1) = newNode;
		return newNode;
	}
	if (index == cslist_length(list)){
		while (cslist_next(node1) != list)
			node1 = cslist_next(node1);
		cslist_next(ndoe1) = newNode;
		cslist_next(newNode) = list;
		return lsit;
	}
	else{
		int i = 1;
		while (cslist_next(node1) != list && i != index){
				node1 = cslist_next(node1);
				i++;
		}
	
		cslist_next(newNode) =  cslist_next(node1);
		cslist_next(node1) = newNode;
		return list;
	}
}

CSList *cslist_remove(CSList *list, unsigned int index){
	if (index < 0 || index >= cslist_length(list)){
		puts("Indice incorrecto.");
		return;
	}
	
	CSList *node = list;
	if (index == 0){
		if (cslist_next(node) == list){
			list = NULL;
			free(list);
			return list;
		}
		list = cslist_next(list);
		node = NULL;
		free(node);
		node = list;
		while (cslist_next(node) != list)
			node = cslist_next(node);
		cslist_next(node) = list;
	}
	else{
		int i = 1;
		node = list;
		while (cslist_next(node) != list && i != index){
			node = cslist_next(node);
			i++;
		}
		cslist_next(node) = cslist_next(cslist_next(node));
		if (cslist_next(node) == list){
			node = NULL;
			free(node);
			return list;
		}
		node = cslist_next(node);
		node = NULL;
		free(node);
	}
	return list;
}

int cslist_contains(CSList *list, int data){
	CSList *node = list;
	if (cslist_length(node) == 1 && cslist_data(node) == data)
		return 1;
	
	while (cslist_next(node) != list){
		if (cslist_data(node) == data)
			return 1;
		node = cslist_next(node);
	}
	
	if (cslist_data(node) == data)
		return 1;
	
	return 0;
}

unsigned int cslist_index(CSList *list, const int data){
	int i = 0;
	CSList *node = list;
	
	if (cslist_length(node) == 1 && cslist_data(node) == data)
		return i;
	
	while (cslist_next(node) != list){
		if(cslist_data(node) == data)
			return i;
		node = cslist_next(node);
		i++;
	}
	
	if(cslist_data(node) == data)
		return i;
}

CSList *cslist_intersect(CSList *list1, CSList *list2){
	CSList *list3 = NULL, *node = list2;
	
	if(cslist_length(node) == 1 && cslist_contains(list1, cslist_data(node))){
		list3 = cslist_append(list3, cslist_data(node));
		return list3;
	}
	int i = 0;
	while(cslist_next(node) != list2){
		if (cslist_contains(list1, cslist_data(node))){
			list3 = cslist_append(list3, cslist_data(node));
			cslist_remove(node, i--);
		}
		node = cslist_next(node);
		i++;
	}
	
	if (cslist_contains(list1, cslist_data(node)))
		list3 = cslist_append(list3, cslist_data(node));
	
	return list3;
}

typedef int (*FunComp)(int a, int b);

CSList *cslist_intersect_custom(CSList *l1, CSList *l2, FunComp f){
	CSList *list3 = NULL, *node1 = l1, *node2 = l2;
	int i = 0;

	if ((cslist_length(node1) == 1 || sclist_length(node2) == 1) && (f(cslist_data(node1), cslist_data(node2)) == 0)){
		list3 = cslist_append(list3, cslist_data(node1));
		return list3;
	}

	while(cslist_next(node1) != l1){
		if (f(cslist_data(node1), cslist_data(node2)) == 0)
			list3 = slist_append(list3, cslist_data(node1));
		node1 = cslist_next(node1);
		node2 = cslist_next(node2);
	}

	if (f(cslist_data(node1), cslist_data(node2)) == 0)
		list3 = cslist_append(list3, cslist_data(node1));

	return list3;
}

/*int compare(const void *a, const void *b){
	return ( *(int*)a - *(int*)b );
}*/

typedef int (*comparar)(const void *, const void *);

CSList *cslist_sort(CSList *list, comparar com){
	int i, *l = malloc(cslist_length(list)*sizeof(int));
	CSList *node = list;
	for(i = 0; i < cslist_length(list); i++){
		*(l+i) = cslist_data(node);
		node = cslist_next(node);
	}

	qsort(l, cslist_length(list), sizeof(int), com);
	
	node = list;
	for(i = 0; i < cslist_length(list); i++){
		cslist_data(node) = *(l+i);
		node = cslist_next(node);
	}
	
	return list;
}