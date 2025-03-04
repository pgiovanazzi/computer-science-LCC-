#include <stdio.h>
#include "SList.h"

void printInt(int data, void *extra_data){
	printf("%d ", data);
}

int main(){
	SList l1 = slist_nil(),l2 = slist_nil(), l3 = slist_nil();
	l1 = slist_append(l1,1);
	l1 = slist_append(l1,2);
	l1 = slist_append(l1,1);

	l2 = slist_prepend(l2,1);
	l2 = slist_prepend(l2,4);
	l2 = slist_prepend(l2,3);

	printf("Lista 1: ");
	slist_foreach(l1, &printInt, NULL);
	puts("");
	printf("Lista 2: ");
	slist_foreach(l2, &printInt, NULL);
	puts("");

	printf("slist_index(l2,4) = %d\n", slist_index(l2,4));
	printf("l1 inter l2 : ");
	l3 = slist_intersect(l1,l2);

	slist_foreach(l3, &printInt, NULL);
	puts("");

	printf("slist_reverse(l2): ");
	l2 = slist_reverse(l2);
	slist_foreach(l2, printInt, NULL);
	puts("");

	slist_destroy(l1);
	slist_destroy(l2);


	return 0;
}
