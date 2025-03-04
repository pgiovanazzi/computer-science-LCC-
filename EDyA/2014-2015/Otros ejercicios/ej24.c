#include <stdio.h>

#define BARRA '/'
#define ASTERISCO '*'
#define NEW_LINE '\n'

typedef enum {
  NORMAL, 
  COMENTARIO_LINEA, 
  COMENTARIO_BLOQUE,
  NO_IMPRIMIR
} modos_codigo;

/*
  Este programa lee por entrada estandar codigo fuente en C
  e imprime por salida estandar codigo sin los comentarios
*/
int main(void) {
  char c = '\0';
  char c_previo = '\0';

  modos_codigo modo = NORMAL;

  // Bucle principal
  while ((c = getchar()) != EOF) {
    
    switch (modo) {
      
    case NORMAL:
      // Comienza un comentario de linea?
      if (BARRA == c && BARRA == c_previo) 
	modo = COMENTARIO_LINEA;
      // Comienza un comentario de bloque?
      else if (ASTERISCO == c && BARRA == c_previo) 
	modo = COMENTARIO_BLOQUE;
      else
	putchar(c_previo);
      break;

    case COMENTARIO_LINEA:
      if (NEW_LINE == c)
	modo = NO_IMPRIMIR;
      break;

    case COMENTARIO_BLOQUE:
      if (BARRA == c && ASTERISCO == c_previo) 
	modo = NO_IMPRIMIR;
      break;

    case NO_IMPRIMIR:
      modo = NORMAL;
      break;
    }

    // Codigo comun a todos los casos
    c_previo = c;

  }
  
  // Imprimir ultimo caracter si corresponde
  if (modo != COMENTARIO_LINEA && modo != COMENTARIO_BLOQUE)
    putchar(c_previo);

  return 0;
}
