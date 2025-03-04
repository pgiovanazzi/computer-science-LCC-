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

	for(idx = 0; idx < size; idx++)
		ht->table[idx] = NULL;
		
	return ht;
}

void hashtable_insert(Hashtable *ht, void *key, void *data){
	unsigned int idx = ht->hash(key, ht->size);
	HashbucketNode *buket = malloc(sizeof(HashbucketNode));
	buket->key = key;
	buket->data = data;
	buket->next = NULL;

	Hashbucket *buketTmp = ht->table[idx];
	HashbucketNode *buketNodeTmp = *buketTmp;

	if (*buketTmp == NULL){
		ht->nelems++;
		*buketTmp = buket;
		return;
	}

	while(buketNodeTmp->next != NULL)
		buketNodeTmp = buketNodeTmp->next;

	buketNodeTmp->next = buket;

	return;
}

void *hashtable_lookup(Hashtable *ht, void *key){
	unsigned int idx = ht->hash(key, ht->size);
	Hashbucket *buketTmp = ht->table[idx];
	HashbucketNode *buketNodeTmp = *buketTmp;
	
	if(ht->equals(key, buketNodeTmp->key))
		return buketNodeTmp->data;
	
	if (buketNodeTmp->key != key)
		return NULL;

	return buketNodeTmp->data;
}

void hashtable_delete(Hashtable *ht, void *key){
	unsigned int idx = ht->hash(key, ht->size);
	Hashbucket *buketTmp = ht->table[idx];
	HashbucketNode *buketNodeTmp = *buketTmp;

	if (*buketTmp != NULL)
		ht->nelems--;

	while(*buketTmp != NULL){
		buketNodeTmp = *buketTmp;
		*buketTmp = (*buketTmp)->next;
		free(buketNodeTmp);
	}
}

void hashtable_destroy(Hashtable *ht){
	int i;
	for(i = 0; i < ht->size; i++){
		Hashbucket *buketTmp = ht->table[i];
		HashbucketNode *buketNodeTmp;
		while(*buketTmp != NULL){
			buketNodeTmp = *buketTmp;
			*buketTmp = (*buketTmp)->next;
			free(buketNodeTmp);
		}
	}
	free(ht->table);
	free(ht);
}
