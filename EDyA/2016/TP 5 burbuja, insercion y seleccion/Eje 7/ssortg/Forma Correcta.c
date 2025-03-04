#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN(X) (sizeof(X) / sizeof(*X))
typedef int (*CmpFunc)(void *, void *);

int cmpInt(void *x, void *y)
{
	return *(int *)x - *(int *)y;
}

void swap(void *d1, void *d2, size_t sz)
{
	void *tmp = malloc(sizeof(sz));
	memcpy(tmp, d1, sz);
	memcpy(d1, d2, sz);
	memcpy(d2, tmp, sz);
	free(tmp);
}

void ssortg(void *data, int len, size_t sz, CmpFunc fn)
{
	for (int i = 0; i < len; i++)
	{
		int min = i;
		for (int j = i + 1; j < len; j++)
			if (fn(data + min * sz, data + j * sz) > 0)
				min = j;
		swap(data + i * sz, data + min * sz, sz);
	}
}

int main(int argc, char *argv[])
{
	int arr[] = {3, 5, 1, 7, 4, 8};

	printf("arr: < ");
	for (int i = 0; i < LEN(arr); i++)
		printf("%i, ", arr[i]);
	printf(" >\n");

	ssortg(arr, LEN(arr), sizeof(int), cmpInt);

	printf("arr: < ");
	for (int i = 0; i < LEN(arr); i++)
		printf("%i, ", arr[i]);
	printf(" >\n");

	return 0;
}