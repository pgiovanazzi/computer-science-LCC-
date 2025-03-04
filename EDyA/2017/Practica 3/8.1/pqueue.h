#ifndef __PQUEUE_H__
#define __PQUEUE_H__

#define MAX_LEN 5

typedef void (*VisitarElementos)(int dato);

typedef struct _APCola
{
	int datos[MAX_LEN];
	int frente;
	int elem;
} APCola;

typedef APCola *PCola;

PCola cola_prioridad_crear();			  /* crea una cola de prioridad. */
int cola_prioridad_es_vacia(PCola);			  /* determina si la cola está vacı́a. */
int cola_prioridad_optener_minimo(PCola);	/* obtiene el elemento proritario. */
void cola_prioridad_eliminar_minimo(PCola); /* quita el elemento prioritario. */
void cola_prioridad_insertar(PCola, int);	/* inserta un elemento con determinada prioridad. */
void cola_prioridad_visitar_elementos(PCola, VisitarElementos); /* visita los elementos. */
void cola_priorida_destruir(PCola); /* destruye una cola de prioridad. */

#endif /* __PQUEUE_H__ */