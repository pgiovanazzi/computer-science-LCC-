
static void intercambiar(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void isort(int datos[], unsigned tam) {
  int j;
  for (unsigned i = 1; i < tam; i++) {
    for (j = i - 1; j >= 0 && datos[j] > datos[j + 1]; j--) {
      intercambiar(&datos[j], &datos[j + 1]);
    }
  }
}