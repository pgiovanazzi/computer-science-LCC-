#include <stdio.h>
#include "DList.h"

void print_int(int data, void *extra_data){
   printf("%d,", data);
}

static void printlist(DList l){
   printf("<");
	dlist_foreach(l,print_int,NULL,0);
	printf("> ");
	printf("<");
	dlist_foreach(l,print_int,NULL,1);
	printf(">");
	puts("");
}

DList dlist_clone(DList list){
   DList clone = NULL;
   for(; list != NULL; list = dlist_next(list))
      clone = dlist_append(clone,dlist_data(list));
   return clone;
}

int cmp(const int *a, const int *b){
	return *a-*b;
}

int main(){
	
	DList l1 ,l2;
	l1 = l2 = dlist_nil();
	
	l1 = dlist_append(l1,2);
	l1 = dlist_append(l1,10);
	l1 = dlist_append(l1,44);
	l1 = dlist_append(l1,20);
	l1 = dlist_append(l1,15);
	
	l2 = dlist_prepend(l2,86);
	l2 = dlist_prepend(l2,10);
	l2 = dlist_prepend(l2,20);
	l2 = dlist_prepend(l2,35);
	
	printf("len(l1) = %i\n", dlist_length(l1));
	printf("len(l2) = %i\n", dlist_length(l2));
	puts("");
	
	printf("l1 = ");printlist(l1);
	printf("l2 = ");printlist(l2);
	
	
	DList clonel1 = dlist_clone(l1);
	DList clonel2 = dlist_clone(l2);
	puts("");
	printf("l1 ++ l2 = "); printlist(dlist_concat(clonel1, clonel2));
	printf("l1 ++ [] = "); printlist(dlist_concat(l1, NULL));
	printf("[] ++ l2 = "); printlist(dlist_concat(NULL, l2));
	puts("");
	printf("dlist_insert(l1,2,3): "); printlist(dlist_insert(l1,2,3));
	printf("dlist_insert(l2,12,0): "); printlist(dlist_insert(l2,12,0));
	l2 = dlist_insert(l2,12,0);
	printf("dlist_insert(l2,64,3): "); printlist(dlist_insert(l2,64,5));
	puts("");
	printf("dlist_remove(l1,3): ");
	l1 = dlist_remove(l1,3);printlist(l1);
	printf("dlist_remove(l2,0): ");
	l2 = dlist_remove(l2,0); printlist(l2);
	printf("dlist_remove(l2,3): ");
	l2 = dlist_remove(l2,3); printlist(l2);
	puts("");
	DList l3 = dlist_intersect_custom(l1,l2,cmp);
	printf("l1 inter l2: "); printlist(l3);
	puts("");
	printf("sort(l1): "); printlist(dlist_sort(l1,cmp));
	printf("sort(l2): "); printlist(dlist_sort(l2,cmp));
	
	
	dlist_destroy(l1);
	dlist_destroy(l2);
	dlist_destroy(clonel1);
	
	return 0;
}
