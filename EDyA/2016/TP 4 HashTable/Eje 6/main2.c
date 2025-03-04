#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

int equals(void *key1, void *key2) {
  int *p = key1;
  int *q = key2;

  return *p == *q;
}

unsigned int stringtonat(char c[]){
  int i = 0, nat = 0;
  for (; c[i]; i++)
    nat += c[i]*128^(i);

  return nat;
}

unsigned int hashnat(unsigned int nat, unsigned int size){
  return nat % size;
}

unsigned int hashstring(char key[], unsigned int size){
  return hashnat(stringtonat(key),size);
}

unsigned int hash(void *key, unsigned int size) {
  int *p = key;
  return *p % size;
}

int main(void) {
  int x = 42, y = 42, z = 3, c = 37, d = 9, h = 9;
  int keychar = hashstring("paul",10);
  Hashtable *ht = hashtable_new(10, hash, equals);

  hashtable_insert(ht, &x, &z);
  hashtable_insert(ht, &d, &c);
  hashtable_insert(ht, &z, &z);
  hashtable_insert(ht, &h, &d);
  hashtable_insert(ht, &keychar, &d);

  printf("z : %d\n", *((int *)hashtable_lookup(ht, &x)));
  printf("z : %d\n", *((int *)hashtable_lookup(ht, &y)));
  printf("d : %d\n", *((int *)hashtable_lookup(ht, &keychar)));

  hashtable_insert(ht, &keychar, &z);
  hashtable_insert(ht, &keychar, &y);
  hashtable_insert(ht, &keychar, &x);

  hastable_printBucket(ht,&keychar);

  ht = hashtable_resize(ht);

  printf("c : %d\n", *((int *)hashtable_lookup(ht, &h)));

  printf("New ziese del Hastable %d\n", ht->size);

  hashtable_destroy(ht);

  return 0;
}
