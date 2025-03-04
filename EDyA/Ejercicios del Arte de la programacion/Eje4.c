#include <math.h>
#include <stdio.h>

/* Cuadrado perfecto y encontrar el cuadrado
 * mas proximo de un entero dado.
 */

// Para compilar se necesita espesiticar la libreria con  -lm

int es_cuadrado(int a) { return sqrt(a) == (int)sqrt(a); }

int es_cuadrado_v2(int n) { return pow(n, 0.5) == (int)pow(n, 0.5); }

int main(int argc, char const *argv[]) {
  int a = 4, i;
  for (i = a; !es_cuadrado(i); i--)
    ;
  printf("El cuadrado mas proximo es: %d\n", i);
  return 0;
}
