#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"

Hashtable *hashtable_new(int size, HashFunc hash, EqualsFunc eqfunc) {
  unsigned int idx;
  Hashtable *ht = malloc(sizeof(Hashtable));

  ht->eqfunc = eqfunc;
  ht->hash = hash;
  ht->size = size;
  ht->table = malloc(sizeof(Hashbucket)*size);
  ht->nelems = 0;

  for (idx = 0; idx < size; idx++)
    ht->table[idx] = NULL;

  return ht;
}

void hashtable_insert(Hashtable *ht, void *key, void *data) {
  unsigned int idx = ht->hash(key,ht->size);
  Hashbucket newBucket = malloc(sizeof(HashbucketNode));
  newBucket->data = data;
  newBucket->key = key;
  newBucket->next = NULL;
  ht->nelems++;
  if (ht->table[idx] == NULL)
    ht->table[idx] = newBucket;
  else{
    Hashbucket node = ht->table[idx];
    while (node->next)
      node = node->next;
    node->next = newBucket;
  }
}

void *hashtable_lookup(Hashtable *ht, void *key) {
  unsigned int idx = ht->hash(key,ht->size);
  if(!ht->table[idx])
    return NULL;
  if (!ht->eqfunc(ht->table[idx]->key,key))
    return NULL;

  return ht->table[idx]->data;
}

void hastable_printBucket(Hashtable *ht, void *key){
  unsigned int idx = ht->hash(key,ht->size);
  if(ht->table[idx]){
    Hashbucket node = ht->table[idx];
    printf("< ");
    while (node) {
      printf("keychar : %d, ", *(int *)node->data);
      node = node->next;
    }
    printf(" >\n");
  }
}

void hashtable_delete(Hashtable *ht, void *key) {
  unsigned int idx = ht->hash(key,ht->size);

  if (ht->table[idx] != NULL){
    ht->nelems--;
    while (ht->table[idx]) {
      Hashbucket node = ht->table[idx];
      ht->table[idx] = ht->table[idx]->next;
      free(node);
    }
  }
}

void hashtable_destroy(Hashtable *ht) {
  for(int i = 0; i < ht->size; i++){
    while (ht->table[i]) {
      Hashbucket node = ht->table[i];
      ht->table[i] = ht->table[i]->next;
      free(node);
    }
  }
  free(ht->table);
  free(ht);
}

// Esta ingresando solamente los primeros valores de la lista
Hashtable *hashtable_resize(Hashtable *ht){
  unsigned int newsize = ht->size*2;
  Hashtable *newHt = hashtable_new(newsize, ht->hash,ht->eqfunc);
  for(int i = 0; i < ht->size; i++)
    if(ht->table[i])
      hashtable_insert(newHt, ht->table[i]->key, ht->table[i]->data);
  hashtable_destroy(ht);
  return newHt;
}
