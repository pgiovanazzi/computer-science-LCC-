#include <stdio.h>
#include <stdlib.h>
#include "bsortg.h"

#define NELEMS(a) 	(int)(sizeof((a))/sizeof(*a))

int cmp(void *a, void *b){
	return (*(int *)a - *(int *)b);
}

int cmpMayor(void *a, void *b){
	return -(*(int *)a - *(int *)b);
}

int cmpString(void *s1, void *s2){
	char *str1 = (char *)s1, *str2 = (char *)s2;
	while (*(char *)str1 && *(char *)str2 && *(char *)str1 - *(char *)str2) {
		str1++;
		str2++;
	}
	return *(char *)str1 - *(char *)str2;
}

int main(void) {
	char strings[][10] = {"Cebolla", "Ajo", "Banana"};

	void **ptr_str = (void **)malloc(sizeof(char *)*3);

	for (int i = 0; i < NELEMS(strings); i++)
		ptr_str[i] = (void *)malloc(sizeof(char)*10);

	for (int i = 0; i < NELEMS(strings); i++)
		ptr_str[i] = strings[i];

	printf("arr: < ");
	for (int i = 0; i < NELEMS(strings); i++)
		printf("%s, ", (char *)ptr_str[i]);
	puts(" >");

	bsortg(ptr_str, NELEMS(strings), cmpString);

	printf("bsortg(arr): < ");
	for (int i = 0; i < NELEMS(strings); i++)
		printf("%s, ", (char *)ptr_str[i]);
	puts(" >");

	free(ptr_str);

  return 0;
}
