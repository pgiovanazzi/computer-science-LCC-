#include <stdio.h>

#define USUARIO     "pepe"
#define CONTRASENIA "1234"

/*
 * Lee entrada estandar hasta un fin de linea y lo compara con cadena
 * Devuelve 1 si la entrada coincide, 0 en otro caso 
 */
int compararEntrada(const char *cadena) {
  int res = 1;
  int pos = 0;
  char c = ' ';
  while ('\n' != (c = getchar()) && ('\0' != cadena[pos]) ) {
    if (c != cadena[pos]) {
      res = 0;
      break;
    } else {
      pos++;
    }
  }
  if (res && ('\n' != c) || ('\0' != cadena[pos]) ) {
    res = 0;
  }
  // Leemos la entrada hasta encontrar un fin de linea
  if ('\n' != c) {
    while ('\n' != getchar())
      ;
  }
  return res;
}

int main(void) {
  printf("Ingrese usuario: ");
  int res = compararEntrada(USUARIO);
  printf("Ingrese contrasenia: ");
  res = compararEntrada(CONTRASENIA) && res;
  if (res) {
    printf("Usuario y contrasenia validos!\n");
  } else {
    printf("Usuario y contrasenia NO validos!\n");
  }

  return 0;
}
