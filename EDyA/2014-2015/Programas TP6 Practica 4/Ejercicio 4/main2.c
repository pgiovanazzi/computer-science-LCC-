#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hashtable.h"

#define PHI		(1 + sqrt(5))/2

unsigned int hashnat(void *key, unsigned int size){
	int *p = key;
	return (int)(size * ((float)(*p*PHI) - (int)(*p*PHI)));
}

unsigned int stringtonat(char *c){
	int i, acum = 0;
	for (i = 0; c[i] != '\0'; i++){
		acum = c[i]*(pow(128, i));
	}
	return acum;
}

unsigned int hashstring(void *key, unsigned int size){
	char *c = key;
	return hashnat((int *)stringtonat(c), size);
}

int equals(void *key1, void *key2) {
	int *p = key1;
	int *q = key2;

	return *p == *q;
}

unsigned int hash(void *key, unsigned int size) {
	int *p = key;
	return *p % size;
}

int main(void) {
	int x = 42, y = 42, z = 3;
	Hashtable *ht = hashtable_new(10, hashnat, equals);

	hashtable_insert(ht, &x, &z);

	printf("z : %d\n", *((int *)hashtable_lookup(ht, &x)));
	printf("z : %d\n", *((int *)hashtable_lookup(ht, &y)));

	hashtable_delete(ht, &x);

	hashtable_destroy(ht);

	return 0;
}
