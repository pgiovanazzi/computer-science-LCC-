#include <stdio.h>
#include "pqueue.h"

void imprimir_enteros(int dato)
{
	printf("%d ", dato);
}

int main(int argc, char *argv[])
{
	PCola pc = cola_prioridad_crear();

	cola_prioridad_insertar(pc, 5);
	cola_prioridad_insertar(pc, 4);
	cola_prioridad_insertar(pc, 3);
	cola_prioridad_insertar(pc, 1);

	cola_prioridad_visitar_elementos(pc, imprimir_enteros);
	puts("");

	cola_prioridad_eliminar_minimo(pc);

	cola_prioridad_visitar_elementos(pc, imprimir_enteros);
	puts("");

	cola_prioridad_insertar(pc, 2);

	cola_prioridad_visitar_elementos(pc, imprimir_enteros);
	puts("");

	cola_prioridad_eliminar_minimo(pc);

	cola_prioridad_visitar_elementos(pc, imprimir_enteros);
	puts("");

	cola_prioridad_insertar(pc, 9);

	cola_prioridad_visitar_elementos(pc, imprimir_enteros);
	puts("");

	cola_priorida_destruir(pc);

	return 0;
}