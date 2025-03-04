static void swap(int *p, int *q) {
  int t = *p;
  *p = *q;
  *q = t;
}

void bsort(int datos[], int tam) {
  int ordenado = 0, i;

  while (!ordenado) {
    ordenado = 1;
    for (i = 0; i < tam - 1; ++i)
      if (datos[i] > datos[i + 1]) {
        ordenado = 0;
        swap(&datos[i], &datos[i + 1]);
      }
  }
}
