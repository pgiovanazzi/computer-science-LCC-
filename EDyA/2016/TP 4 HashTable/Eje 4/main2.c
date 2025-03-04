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
  int x = 42, y = 42, z = 3, c = 37;
  char key[] = "Ricardo Arjona";
  char tel[] = "1234567";
  int strinNat = hashstring(key,10);
  // Lo vuelve a rehashear los strings con la funcion hash asignada en hashtable_new()
  // cuando insertamos un nuevo la clave strinNat (en eje 3 esta correcto).
  Hashtable *ht = hashtable_new(10, hash, equals);

  hashtable_insert(ht, &x, &z);
  hashtable_insert(ht, &strinNat, tel);

  printf("z : %d\n", *((int *)hashtable_lookup(ht, &x)));
  printf("z : %d\n", *((int *)hashtable_lookup(ht, &y)));
  printf("tel : %s\n", ((char *)hashtable_lookup(ht, &strinNat)));

  hashtable_delete(ht, &x);

  hashtable_destroy(ht);

  return 0;
}
