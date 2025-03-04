#include "bsortg.h"
#include <stdlib.h>
#include <string.h>

void swap(void *p, void *q, size_t sz)
{
	void *temp = malloc(sz);
	memcpy(temp, q, sz);
	memcpy(q, p, sz);
	memcpy(p, temp, sz);
	free(temp);
	return;
}

void bsortg(void *data, int len, size_t sz, CmpFunc func)
{
	int sorted, i;

	do
	{
		sorted = 1;
		for (i = 0; i < len - 1; i++)
			if (func(data + i * sz, data + (i + 1) * sz) > 0)
			{
				sorted = 0;
				swap(data + i * sz, data + (i + 1) * sz, sz);
			}
	} while (sorted != 1);
}