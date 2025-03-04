#include <stdio.h>
#include "bsortg.h"

#define NELEMS(a) (sizeof((a))/sizeof(int))

int compareStr(void* a, void* b)
{
	while(*(const char *)a && (*(const char *)a == *(const char *)b))
		(const char *)a++, (const char *)b++;
	return *(const unsigned char *)b-*(const unsigned char *)a;
}

int main(void) {
	char* arr[] = {"d","c", "b","a"};
	int i;

	bsortg((void *)arr, NELEMS(arr), compareStr);

	for (i  = 0; i < NELEMS(arr); i++)
		printf("%s ", arr[i]);
	puts("");

  return 0;
}
