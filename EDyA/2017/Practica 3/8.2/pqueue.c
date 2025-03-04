#include <stdlib.h>
#include "pqueue.h"

PCola cola_prioridad_crear()
{
	PCola nuevaCola = NULL;
	return nuevaCola;
}

int cola_prioridad_es_vacia(PCola pc)
{
	return (pc) ? 0 : 1;
}

int cola_prioridad_obtener_minimo(PCola pc)
{
	return pc->dato;
}

PCola cola_prioridad_eliminar_minimo(PCola pc)
{
	if (!cola_prioridad_es_vacia(pc))
	{
		PCola nodo = pc;
		pc = pc->sig;
		free(nodo);
	}
	return pc;
}

PCola cola_prioridad_insertar(PCola pc, int dato)
{
	PCola nuevoNodo = malloc(sizeof(SLPNodo));
	nuevoNodo->dato = dato;
	nuevoNodo->sig = NULL;

	if (cola_prioridad_es_vacia(pc))
		return nuevoNodo;

	PCola nodo = pc;
	while (nodo->sig && nodo->sig->dato < nuevoNodo->dato)
		nodo = nodo->sig;

	if (cola_prioridad_es_vacia(nodo->sig))
		if ( nodo->dato < nuevoNodo->dato)
			nodo->sig = nuevoNodo;
		else
		{
			nuevoNodo->sig = nodo;
			return nuevoNodo;
		}
	else
	{
		nuevoNodo->sig = nodo->sig;
		nodo->sig = nuevoNodo;
	}
	return pc;
}

void cola_prioridad_destruir(PCola pc)
{
	while (pc)
	{
		PCola nodo = pc;
		pc = pc->sig;
		free(nodo);
	}
}

void cola_prioridad_imprimir(PCola pc, FuncionVisitante visitar)
{
	for (PCola nodo = pc; nodo; nodo = nodo->sig)
		visitar(nodo->dato);
}