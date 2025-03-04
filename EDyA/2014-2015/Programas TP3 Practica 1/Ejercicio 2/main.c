#include <stdio.h>
#include <stdlib.h>
#include "SList.h"

static void print_int (int data, void *extra_data){
	   printf("%d ", data);
}

int compare(const void *a, const void *b){
	return ( *(int*)a - *(int*)b );
}

int main(int argc, char *argv[]){
	
	SList *list = NULL, *list1 = NULL, *l3 = NULL;
	int i;
	
	list = slist_prepend(list, 5);
	list = slist_prepend(list, 2);
	list = slist_prepend(list, 3);
	list = slist_append(list, 4);
	list1 = slist_prepend(list1, 5);
	list1 = slist_prepend(list1, 3);
	list1 = slist_prepend(list1, 3);

	slist_foreach(list, print_int, NULL);
	
	puts("");

	slist_foreach(list1, print_int, NULL);
	
	puts("");
	
	l3 = slist_concat(NULL, NULL);
	
	slist_foreach(l3, print_int, NULL);
	
	puts("");
	slist_destroy(list);

	return 0;
}