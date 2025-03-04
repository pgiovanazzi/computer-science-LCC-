#ifndef __BHeap_H__
#define __BHeap_H__

#define MAX_HEAP 128

typedef struct _BHeap{
  int data[MAX_HEAP];
  int nelems;
} BHeap;

#define SWAP(a,b)   {int t = a; a = b; b = t;}

BHeap *bheap_create(); //crea un heap.
int bheap_minimum(BHeap *); //toma un heap y devuelve el menor elemento.
void bheap_erase_minimum(BHeap *); //toma un heap y borra su menor elemento.
void bheap_insert(BHeap * , int); //toma un heap y agrega un elemento.
void bheap_print(BHeap *); //toma un heap e imprime sus elementos utilizando el orden “Primero por Extensión”.
void bheap_destroy(BHeap *); //toma un heap y lo destruye.
int bheap_is_empty(BHeap *); //toma un heap y dice si esta vacio.

#endif
