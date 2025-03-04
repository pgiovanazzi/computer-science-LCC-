
static void intercambiar(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

static int particionar(int arr[], int inicial, int final) {
  int izq = inicial;
  int der = final;
  int pivote = arr[(inicial + final) / 2];
  while (izq < der) {
		
    while (arr[izq] < pivote)
      izq++;
    while (arr[der] > pivote)
      der--;

    intercambiar(&arr[izq], &arr[der]);
  }
  return der;
}

void qsort_(int arr[], int init, int last) {
  if (init < last) {
    int pivote = particionar(arr, init, last);
    qsort_(arr, init, pivote - 1);
    qsort_(arr, pivote + 1, last);
  }
}