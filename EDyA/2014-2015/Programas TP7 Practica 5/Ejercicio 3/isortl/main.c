#include "isortl.h"
#include <stdlib.h>
#include <stdio.h>

void slist_print(int data, void *extra_data){
	printf("%d ", data);
}

int main(int argc, char const *argv[])
{
	SList *l1 = NULL;

	l1 = slist_append(l1, 3);
	l1 = slist_append(l1, -3);
	l1 = slist_append(l1, 5);
	l1 = slist_append(l1, 1);
	l1 = slist_append(l1, 2);
	l1 = slist_append(l1, 6);

	slist_foreach(l1, slist_print, NULL);
	puts("");

	isortl(l1);

	slist_foreach(l1, slist_print, NULL);
	puts("");

	slist_destroy(l1);

	return 0;
}