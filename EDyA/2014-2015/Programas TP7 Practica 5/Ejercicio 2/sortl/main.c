#include "SList.h"
#include "ssortl.h"
#include <stdlib.h>
#include <stdio.h>

void slist_print(int data, int* extra_data)
{
	printf("%d, ", data);
	return;
}

void slist_min(int data, int* extra_data)
{
	if(data < *(int *)extra_data)
		*(int *)extra_data = data;
	return;
}

int main(int argc, char const *argv[])
{
	SList *l1 = NULL, *l2 = NULL;
	int m;

	l1 = slist_append(l1, 10);
	l1 = slist_append(l1, 1);
	l1 = slist_append(l1, -3);
	l1 = slist_append(l1, 5);

	l2 = slist_prepend(l2, 10);
	l2 = slist_prepend(l2, 20);
	l2 = slist_append(l2, 5);

	slist_foreach(l1, slist_print, NULL);
	puts("");

	l1 = ssortl(l1, slist_min, &m);

	slist_foreach(l1, slist_print, NULL);
	puts("");

	slist_destroy(l1);
	slist_destroy(l2);

	return 0;
}