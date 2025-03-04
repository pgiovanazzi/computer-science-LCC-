#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN(a) (int)(sizeof(a) / sizeof(*a))

typedef int (*CmpFunc)(void *, void *);

int cmpInt(void *x, void *y)
{
	return *(int *)x - *(int *)y;
}

void swap(void *d1, void *d2, size_t sz)
{
	void *t = malloc(sizeof(sz));
	memcpy(t, d1, sz);
	memcpy(d1, d2, sz);
	memcpy(d2, t, sz);
	free(t);
}

void bsortg(void *arr, int len, size_t sz, CmpFunc func)
{
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len - 1; j++)
			if (func(arr + j * sz, arr + (j + 1) * sz) > 0)
				swap(arr + j * sz, arr + (j + 1) * sz, sz);
}

int main(int argc, char *argv[])
{
	int arr[] = {3, 1, 2, 6, 4, 5};

	printf("bsortg(arr): < ");
	for (int i = 0; i < LEN(arr); i++)
		printf("%i, ", arr[i]);
	puts(">");

	bsortg(arr, LEN(arr), sizeof(int), cmpInt);

	printf("bsortg(arr): < ");
	for (int i = 0; i < LEN(arr); i++)
		printf("%i, ", arr[i]);
	puts(">");

	return 0;
}