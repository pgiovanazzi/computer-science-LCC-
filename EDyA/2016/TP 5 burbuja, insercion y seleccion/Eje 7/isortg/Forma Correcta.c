#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN(X)      (sizeof(X)/sizeof(*X))
typedef int (*CmpFunc)(void *, void *);

int cmpInt(void *a, void *b)
{
	return *(int *)a - *(int *)b;
}

void swap(void *d1, void *d2, size_t sz)
{
	void *t = malloc(sizeof(sz));
	memcpy(t, d1, sz);
	memcpy(d1, d2, sz);
	memcpy(d2, t, sz);
	free(t);
}

void isortg(void *data, int len, size_t sz, CmpFunc cmp)
{
	for (int i = 0; i < len; i++)
	{
		int prev = i, j = i + 1;
		while (prev > -1 && j < len && cmp(data + prev * sz, data + j * sz) > 0)
			swap(data + prev-- * sz, data + j-- * sz, sz);
	}
}

int main(int argc, char *argv[])
{
	int arr[] = {3, 1, 7, 4, 9, 5};

	printf("isortg(arr): < ");
	for (int i = 0; i < LEN(arr); i++)
		printf("%i, ", arr[i]);
	puts(" >");

	isortg(arr, LEN(arr), sizeof(int), cmpInt);

	printf("isortg(arr): < ");
	for (int i = 0; i < LEN(arr); i++)
		printf("%i, ", arr[i]);
	puts(" >");

	return 0;
}