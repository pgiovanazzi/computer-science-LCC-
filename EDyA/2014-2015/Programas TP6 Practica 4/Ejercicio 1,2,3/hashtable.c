#include <stdlib.h>
#include "hashtable.h"

Hashtable *hashtable_new(int size, HashFunc hash, EqualsFunc equals){
	unsigned int idx;
	Hashtable *ht = malloc(sizeof(Hashtable));

	ht->equals = equals;
	ht->hash = hash;
	ht->size = size;
	ht->table = malloc(sizeof(Hashbucket)*size);
	ht->nelems = 0;
	
	for (idx = 0; idx < size; idx++) {
		ht->table[idx].key = NULL;
		ht->table[idx].data = NULL;
	}

	return ht;
}

void hashtable_insert(Hashtable *ht, void *key, void *data){
	unsigned int idx = ht->hash(key);

	if (ht->table[idx].key == NULL)
		ht->nelems++;

	ht->table[idx].key = key;
	ht->table[idx].data = data;
}

void *hashtable_lookup(Hashtable *ht, void *key){
	unsigned int idx = ht->hash(key);
	
	if(ht->equals(key, ht->table[idx].key))
		return ht->table[idx].data;
	return NULL;
	
	/*if (ht->table[idx].key != key)
		return NULL;

	return ht->table[idx].data;*/
}

void hashtable_delete(Hashtable *ht, void *key){
	unsigned int idx = ht->hash(key);

	if (ht->table[idx].key != NULL)
		ht->nelems--;

	ht->table[idx].key = NULL;
	ht->table[idx].data = NULL;
}

void hashtable_destroy(Hashtable *ht){
	free(ht->table);
	free(ht);
}
