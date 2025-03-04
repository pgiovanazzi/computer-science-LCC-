#ifndef __PQUEUE_H__
#define __PQUEUE_H__

#define MAX_PQUEUE 20
#define HIJOS(H) (H * 2 + 1)
#define PADRE(P) ((P - 1) / 2)
#define INTERCAMBIAR(A, B)                                                     \
  {                                                                            \
    int tmp = A;                                                               \
    A = B;                                                                     \
    B = tmp;                                                                   \
  }

typedef void (*FuncionVisitador)(int dato);

typedef struct _pqueue {
  int datos[MAX_PQUEUE];
  int elementos;
} pqueue;

typedef pqueue *PCola;

PCola cola_prioridad_crear();
int cola_prioridad_es_vacia(PCola);
void cola_prioridad_eliminar_minimo(PCola);
int cola_prioridad_obtener_minimo(PCola);
void cola_prioridad_insertar(PCola, int);
void cola_prioridad_imprimir(PCola, FuncionVisitador);
void cola_prioridad_destruir(PCola);

#endif /* __PQUEUE_H__ */