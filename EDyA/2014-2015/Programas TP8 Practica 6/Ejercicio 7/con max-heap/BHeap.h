#ifndef __BHEAP_H__
#define __BHEAP_H__

#define MAX_HEAP 128

typedef struct _BHeap{
	int data[MAX_HEAP];
	int nelems;
} BHeap;


//Crea un heap.
BHeap* bheap_create();

//Toma un heap y verifica si esta vacía.
int bheap_is_empty(BHeap *heap);

//Toma un heap y devuelve el menor elemento.
int bheap_maximun(BHeap *heap);

//Toma un heap y borra su menor elemento.
void bheap_erase_maximun(BHeap *heap);

//Toma un heap y agrega un elemento.
void bheap_insert(BHeap *heap, int elem);

//Toma un heap e imprime sus elementos utilizando el orden "Primero por Extensión".
void bheap_print(BHeap *heap);

//Toma un heap y la destruye.
void  bheap_destroy(BHeap *heap);

#endif /*__BHEAP_H__*/