#include <stdio.h>
#include <stdlib.h>
#include "ASList.h"

void printData(const int data, void *extra_data){
	printf("%i,", data);
}

void printList(ASList list){
	printf("<");
	aslist_foreach(list, printData, NULL);
	printf(">");
	puts("");
}

int main(){
	ASList list = aslist_create();

	list = aslist_append(list,5);
	list = aslist_append(list,4);
	list = aslist_append(list,10);
	list = aslist_append(list,43);
	list = aslist_append(list,15);

	printf("list: ");

	printList(list);

	printf("aslist_insert(list,9,2): ");
	list = aslist_insert(list,9,2); printList(list);
	printf("aslist_insert(list,99,6): ");
	list = aslist_insert(list,99,6); printList(list);
	printf("aslist_insert(list,43,6): ");
	list = aslist_insert(list,43,6); printList(list);
	printf("aslist_insert(list,63,8): ");
	list = aslist_insert(list,63,8); printList(list);

	aslist_destroy(list);

	return 0;
}
