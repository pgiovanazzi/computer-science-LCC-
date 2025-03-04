#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

int equals(void *key1, void *key2)
{
	int *p = key1;
	int *q = key2;

	return *p == *q;
}

unsigned int stringtonat(char c[])
{
	int i = 0, nat = 0;
	for (; c[i]; i++)
		nat += c[i] * 128 ^ (i);

	return nat;
}

unsigned int hashnat(unsigned int nat)
{
	return nat % 10;
}

unsigned int hashstring(void *str)
{
	return hashnat(stringtonat(str));
}

unsigned int hash(void *key)
{
	int *p = key;
	return *p % 10;
}

int main(void)
{
	int x = 42, y = 42, z = 3, c = 37;
	char key[] = "1234";
	char p[] = "Jorgito";
	char *str = malloc(sizeof(char));
	str = "hola";
	Hashtable *ht = hashtable_new(10, hashstring, equals);

	hashtable_insert(ht, key, str);
	hashtable_insert(ht, str, &x);
	hashtable_insert(ht, p, &z);

	printf("str : %s\n", ((char *)hashtable_lookup(ht, key)));
	printf("x : %d\n", *((int *)hashtable_lookup(ht, str)));
	printf("z : %d\n", *((int *)hashtable_lookup(ht, p)));

	hashtable_delete(ht, &x);

	hashtable_destroy(ht);

	return 0;
}
