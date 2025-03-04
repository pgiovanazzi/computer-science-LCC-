#include <stdio.h>
#include "SList.h"

void printInt(int data, void *extra_data)
{
	printf("%d ", data);
}

int genericCmp(const void *a, const void *b)
{
	int fst = *(int *)a;
	int scd = *(int *)b;
	return fst - scd;
}

int main()
{
	SList l1 = slist_nil(), l2 = slist_nil(), l3 = slist_nil();
	l1 = slist_append(l1, 1);
	l1 = slist_append(l1, 2);
	l1 = slist_append(l1, 1);

	l2 = slist_prepend(l2, 1);
	l2 = slist_prepend(l2, 4);
	l2 = slist_prepend(l2, 1);

	slist_foreach(l1, &printInt, NULL);
	puts("");
	slist_foreach(l2, &printInt, NULL);
	puts("");

	printf("El index es %d\n", slist_index(l2, 4));

	// l3 = slist_intersect(l1, l2);
	l3 = slist_intersect_custom(l1, l2, genericCmp);

	slist_foreach(l3, &printInt, NULL);
	puts("");

	slist_destroy(l1);
	slist_destroy(l2);

	return 0;
}
