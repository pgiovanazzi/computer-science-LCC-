#include <stdio.h>
#include "pqueue.h"

void imprimir_entero(int dato)
{
	printf("%d ", dato);
}

int main(int argc, char *argv[])
{
	PCola pc = cola_prioridad_crear();

	pc = cola_prioridad_insertar(pc, 5);
	pc = cola_prioridad_insertar(pc, 1);
	pc = cola_prioridad_insertar(pc, 7);
	pc = cola_prioridad_insertar(pc, 2);

	cola_prioridad_imprimir(pc, imprimir_entero);
	puts("");
	
	pc = cola_prioridad_eliminar_minimo(pc);
	
	cola_prioridad_imprimir(pc, imprimir_entero);
	puts("");

	cola_prioridad_destruir(pc);

	return 0;
}