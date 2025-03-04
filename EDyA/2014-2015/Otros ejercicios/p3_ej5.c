#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AStack.h"

#define DELIM " "

int main() {
  
  AStack *pila = astack_create();
  
  // Leer expresion
  char *line = NULL;
  size_t line_len = 0;
  line_len = getline(&line, &line_len, stdin);

  // Descomentar para ver que leimos. Ver que incluye el '\n'.
  /* printf("longitud: %zu\n", line_len); */
  /* printf("linea: [%s]\n", line); */

  // Eliminar el '\n'
  line[line_len - 1] = '\0';

  // Parsear entrada
  char *pch;
  int op1, op2;
  for (pch = strtok (line, DELIM); 
       pch != NULL;
       pch = strtok(NULL, DELIM)) {

    /* printf ("procesando: [%s]\n", pch); */

    // Si es un numero, agregarlo a la pila
    switch(pch[0]) {
    case '+':
      op1 = astack_top(pila);
      astack_pop(pila);
      op2 = astack_top(pila);
      astack_pop(pila);      
      astack_push(pila, op1 + op2);
      break;

    case '-':
      // TODO
      break;

    case '*':
      // TODO
      break;

    default: // Numero
      astack_push(pila, atoi(pch));
      break;
    } 
    
  }

  /* astack_print(pila); */

  printf("Resultado: %d\n", astack_top(pila));

  // Liberamos recursos
  free(line);
  astack_destroy(pila);

  return 0;
}
