#ifndef __DLIST_H__
#define __DLIST_H__

typedef void (*FuncionVisitante)(int dato);
typedef enum {
	DLIST_RECORRIDO_HACIA_ADELANTE,
	DLIST_RECORRIDO_HACIA_ATRAS
} DListOrdenDeRecorrido;

typedef struct _Limites
{
	int inicio, final;
} Limites;

typedef struct _DNodo
{
	int dato;
	Limites *limite;
	struct _DNodo *sig, *prev;
} DNodo;

typedef DNodo *DList;

DList dlist_crear();
void dlist_destruir(DList lista);
int dlist_vacia(DList lista);
DList dlist_agregar_final(DList lista, int dato);
DList dlist_agregar_inicio(DList lista, int dato);
void dlist_recorrer(DList lista, FuncionVisitante visita, DListOrdenDeRecorrido orden);
int dlist_longitud(DList lista);
DList dlist_concatenar(DList lista1, DList lista2);

#endif /* __DLIST_H__ */