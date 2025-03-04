#include <stdio.h>
#include <stdlib.h>

#define LEN(arr) sizeof(arr) / sizeof(int)

int cmpCtvo(const void* p, const void* q) {
  return *(int*)q - *(int*)p;
}

void solve(int ctvo[], int sz, int total) {
  int i, possible_ctvo = 0, acum = 0;

  qsort(ctvo, sz, sizeof(int), cmpCtvo);

  puts("Sentavos elegidos:");

  for (i = 0; i < sz; i++)
    while (acum + ctvo[i] <= total) {
      printf("%d ", ctvo[i]);
      acum += ctvo[i];
      possible_ctvo++;
    }

  printf(".\nTotal de Centavos minimos: %d.\n", possible_ctvo);
}

int main(int argc, char const* argv[]) {
  int centavos[] = {1, 5, 10, 20};
  int number_of_C, i;

  puts("Ingrese constante C:");
  scanf("%d", &number_of_C);

  solve(centavos, LEN(centavos), number_of_C);

  return 0;
}