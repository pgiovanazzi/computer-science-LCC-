#ifndef __PQUEUE_H__
#define __PQUEUE_H__

typedef void (*FuncionVisitante)(int);

typedef struct _SLPNodo
{
	int dato;
	struct _SLPNodo *sig;
} SLPNodo;

typedef SLPNodo *PCola;

PCola cola_prioridad_crear();
int cola_prioridad_es_vacia(PCola);
int cola_prioridad_obtener_minimo(PCola);
PCola cola_prioridad_eliminar_minimo(PCola);
PCola cola_prioridad_insertar(PCola, int);
void cola_prioridad_destruir(PCola);
void cola_prioridad_imprimir(PCola,FuncionVisitante);

#endif /* __PQUEUE_H__ */