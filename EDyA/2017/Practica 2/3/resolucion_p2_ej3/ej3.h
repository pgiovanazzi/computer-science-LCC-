#ifndef __EJ3_H__
#define __EJ3_H__

#include <stddef.h>

typedef struct lista_ {
  size_t tamanio;
  int *datos;
  int *siguientes;
  char *usados;
  int primero;
  int ultimo;
} lista;



lista* lista_crear(size_t);
void lista_destruir(lista*);
int lista_agregar_final(lista*, int);
int lista_agregar_principio(lista*, int);
void lista_imprimir(lista*);

#endif
