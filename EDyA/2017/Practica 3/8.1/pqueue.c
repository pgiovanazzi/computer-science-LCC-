#include <stdlib.h>
#include "pqueue.h"

PCola cola_prioridad_crear()
{
	PCola nuevaColaDePrioridad = malloc(sizeof(APCola));
	nuevaColaDePrioridad->frente = 0;
	nuevaColaDePrioridad->elem = 0;
}

int cola_prioridad_es_vacia(PCola pCola)
{
	return (pCola->elem) ? 0 : 1;
}

int cola_prioridad_optener_minimo(PCola pCola)
{
	return pCola->datos[pCola->frente];
}

void cola_prioridad_eliminar_minimo(PCola pCola)
{
	if (cola_prioridad_es_vacia(pCola))
		return;
	pCola->frente = (pCola->frente + 1) % MAX_LEN;
	pCola->elem--;
}

void cola_prioridad_insertar(PCola pCola, int dato)
{
	if (pCola->elem == MAX_LEN)
		return;

	int idx = (pCola->elem++ + pCola->frente) % MAX_LEN;
	int swap = pCola->frente;
	int tmp;

	pCola->datos[idx] = dato;
	while (pCola->datos[swap] < pCola->datos[idx])
		swap = (swap + 1) % MAX_LEN;
	while (swap != idx)
	{
		tmp = pCola->datos[swap];
		pCola->datos[swap] = pCola->datos[idx];
		pCola->datos[idx] = tmp;
		swap = (swap + 1) % MAX_LEN;
	}
}

void cola_prioridad_visitar_elementos(PCola pCola, VisitarElementos visitar)
{
	int numElm = pCola->elem;
	for (size_t i = pCola->frente; numElm; i = (i + 1) % MAX_LEN, numElm--)
		visitar(pCola->datos[i]);
}

void cola_priorida_destruir(PCola pCola)
{
	free(pCola);
}