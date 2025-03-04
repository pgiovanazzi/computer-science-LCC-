#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

unsigned int hash(void *key){
	int *p = key;
	return *p % 10;
}

int main(void){
	int x = 42, y = 42, z = 3;
	Hashtable *ht = hashtable_new(10, hash);

	hashtable_insert(ht, &x, &z);
	hashtable_insert(ht, &y, &z);
	
	printf("z : %d\n", *((int *)hashtable_lookup(ht, &x)));
	printf("z : %d\n", *((int *)hashtable_lookup(ht, &y)));

	hashtable_delete(ht, &x);

	hashtable_destroy(ht);

	return 0;
}
