#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

typedef unsigned int (*HashFunc)(void *, unsigned int);
typedef int (*EqualsFunc)(void *,void *);

typedef struct _HashbucketNode {
  void *key;
  void *data;
  struct _HashbucketNode *next;
} HashbucketNode;

typedef HashbucketNode *Hashbucket;

typedef struct _Hashtable {
  Hashbucket *table;
  int nelems, size;
  HashFunc hash;
  EqualsFunc eqfunc;
} Hashtable;

Hashtable *hashtable_new(int, HashFunc, EqualsFunc);
void hashtable_insert(Hashtable *, void *, void *);
void *hashtable_lookup(Hashtable *, void *);
void hashtable_delete(Hashtable *, void *);
void hashtable_destroy(Hashtable *);
//Es necesario cerar la funcion que imprima las cuebetas anidadas.
void hastable_printBucket(Hashtable *, void *);
//Ejercicio 6:
Hashtable *hashtable_resize(Hashtable *);

#endif /* __HASHTABLE_H__ */
