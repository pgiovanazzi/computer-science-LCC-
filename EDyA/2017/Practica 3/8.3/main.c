#include "pqueue.h"
#include <stdio.h>

static void imprimir_entero(int dato) { printf("%d ", dato); }

int main(int argc, char *argv[]) {
  PCola cp = cola_prioridad_crear();
  cola_prioridad_insertar(cp, 5);
  cola_prioridad_insertar(cp, 1);
  cola_prioridad_insertar(cp, 4);
  cola_prioridad_insertar(cp, 3);
  cola_prioridad_insertar(cp, 2);
  cola_prioridad_insertar(cp, 6);

  cola_prioridad_imprimir(cp, imprimir_entero);
  puts("");

  cola_prioridad_eliminar_minimo(cp);
  cola_prioridad_imprimir(cp, imprimir_entero);
  puts("");

  cola_prioridad_eliminar_minimo(cp);
  cola_prioridad_imprimir(cp, imprimir_entero);
  puts("");

  printf("Maxima prioridad: %d\n", cola_prioridad_obtener_minimo(cp));

  cola_prioridad_destruir(cp);

  return 0;
}