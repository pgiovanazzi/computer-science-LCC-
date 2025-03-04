#include <stdio.h>
#include <stdlib.h>
#include "CSList.h"

void printInt(int data, void *extra_data){
	printf("%i,", data);
}

void printlist(CSList list){
	printf("<");
	cslist_foreach(list,printInt,NULL);
	printf(">\n");
}

int cmp(const int *a,const int *b){
	return *a-*b;
}

CSList clone(CSList list){
	CSList lclone = malloc(sizeof(CSNode)),node = list;
	lclone = cslist_nil();
	do{
		lclone = cslist_append(lclone,cslist_data(node));
		node = cslist_next(node);
	}while(node != list);
	return lclone;
}

int main(){
	CSList l1,l2;
	
	l1 = l2 = cslist_nil();
	
	l1 = cslist_append(l1,2);
	l1 = cslist_append(l1,35);
	l1 = cslist_append(l1,67);
	l1 = cslist_append(l1,1);
	
	l2 = cslist_prepend(l2,12);
	l2 = cslist_prepend(l2,5);
	l2 = cslist_prepend(l2,1);
	l2 = cslist_prepend(l2,2);
	
	printf("l1 = ");printlist(l1);
	printf("l2 = ");printlist(l2);
	
	printf("len(l1): ");printf("%d\n",cslist_length(l1));
	printf("len(l2): ");printf("%d\n",cslist_length(l1));
	
	CSList l1clone = clone(l1);
	CSList l2clone = clone(l2);
	
	printf("l1 ++ l2 = ");printlist(cslist_concat(l1clone,l2clone));
	printf("l1 ++ [] = ");printlist(cslist_concat(l1,NULL));
	printf("[] ++ l2 = ");printlist(cslist_concat(NULL,l2));
	
	l2 = cslist_remove(l2,0);
	printf("remove(l2,0) = ");printlist(l2);
	
	
	l1 = cslist_insert(l1,12,2);
	printf("cslist_insert(l1,12,2) = ");printlist(l1);
	l1 = cslist_insert(l1,43,4);
	printf("cslist_insert(l1,43,4) = ");printlist(l1);
	
	printf("l1 inter l2 = ");printlist(cslist_intersect(l1,l2));
	
	printf("sort(l1) = ");printlist(cslist_sort(l1,cmp));
	printf("sort(l2) = ");printlist(cslist_sort(l2,cmp));
	
	cslist_destroy(l1);
	cslist_destroy(l2);
	cslist_destroy(l1clone);
	cslist_destroy(l2clone);
	
	return 0;
}
