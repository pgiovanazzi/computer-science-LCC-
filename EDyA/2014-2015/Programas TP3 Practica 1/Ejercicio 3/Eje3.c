#include <stdlib.h>
#include <stdio.h>
#include "SList.h"
#include "Eje3.h"

SList *create(int data, SList *next){
	SList *newNode = malloc(sizeof(SList));
	slist_data(newNode) = data;
	slist_next(newNode) =  next;
	return newNode;
}

void  destroy(SList *list){
	destroy(list);
}

static void print_int (int data, void *extra_data){
       printf("%d, ", data);
}

void  print(SList *list){
	slist_foreach(list, print_int, NULL);
	puts("");
}

SList * add_end(SList *list, int elem){
	list = slist_append(list, elem);
	return list;
}

SList * add_beg(SList *list, int elem){
	list = slist_prepend(list, elem);
	return list;
}

SList * add_pos(SList *list, int elem, unsigned int pos){
	list = slist_insert(list, elem, pos);
	return list;
}

void length(SList *list){
	printf("%d", slist_length(list));
}

SList *concat(SList *l1, SList *l2, SList *l3){
	SList *node = l3;
	node = slist_concat(l1,l2);
	return node;
}

SList *removes(SList *list, unsigned int pos){
	list = slist_remove(list, pos);
	return list;
}

void contais(SList *list, int elem){
	if (slist_contains(list, elem))puts("SI");
	else puts("NO");
}

void indexs(SList *list, int elem){
	printf("%d", slist_index(list,elem));
}

SList *intersect(SList *l1, SList *l2, SList *l3){
	l3 = slist_intersect(l1,l2);
	return l3;
}

int compare(const void *a, const void *b){
	return ( *(int*)a - *(int*)b );
}

SList *sort(SList *list){
	slist_sort(list, compare);
	return list;
}