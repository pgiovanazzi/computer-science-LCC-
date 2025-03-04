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

void printInt(void *data)
{
	printf("%d, ", *(int *)data);
}

int main(void) {
  int x = 42, y = 42, z = 3, c = 37, d = 9;
  int keychar = hashstring("paul",10);
  Hashtable *ht = hashtable_new(10, hash, equals);

  hashtable_insert(ht, &x, &z);
  hashtable_insert(ht, &keychar, &c);
  hashtable_insert(ht, &keychar, &z);
  hashtable_insert(ht, &keychar, &d);

  printf("z : %d\n", *((int *)hashtable_lookup(ht, &x)));
  printf("z : %d\n", *((int *)hashtable_lookup(ht, &y)));
  printf("c : %d\n", *((int *)hashtable_lookup(ht, &keychar)));

  hastable_printBucket(ht,&keychar, printInt);

  hashtable_delete(ht, &x);

  hashtable_destroy(ht);

  return 0;
}
