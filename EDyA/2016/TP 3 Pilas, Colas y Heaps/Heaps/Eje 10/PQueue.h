#ifndef __PQueue_H__
#define __PQueue_H__

#define MAX_PQUEUE 20

typedef struct _dataPrioty {
  int d;
  int prioty;
} dataPrioty;

typedef dataPrioty *DP;

typedef struct _BHeap {
  DP *data;
  int nelems;
} BHeap;

typedef struct _PQueue {
  BHeap *heap;
  int front, back;
} PQueue;

#define SWAP(a, b)                                                             \
  {                                                                            \
    DP t = a;                                                                  \
    a = b;                                                                     \
    b = t;                                                                     \
  }

#define PARENT(X) ((X - 1) / 2)
#define CHILD(X) (X * 2 + 1)

unsigned short bheap_is_empty(BHeap *); // Dice si el heap esta vacio.
BHeap *bheap_insert(BHeap *, DP);       // Toma un heap y agrega un elemento.
BHeap *bheap_create();                  // Trea un heap.
DP bheap_minimum(BHeap *); // Toma un heap y devuelve el menor elemento.
BHeap *bheap_erase_minimum(BHeap *); // Toma un heap y borra su menor elemento.
void bheap_destroy(BHeap *);         // Destruye el heap.

// Crea una cola de prioridad.
PQueue *pqueue_create();

// Encola un dato con su prioridad.
void pqueue_enqueue(PQueue *q, int data, int priority);

// Quita el elemento con mas prioridad.
void pqueue_dequeue(PQueue *q);

// Devuelve el elemento con mas prioridad.
int pequeue_front(PQueue *q);

// Imprime los elementos segun su prioridad.
void pqueue_print(PQueue *q);

// Destruye la cola
void pqueue_desroy(PQueue *q);

#endif
