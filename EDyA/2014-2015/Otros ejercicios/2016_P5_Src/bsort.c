void swap(int *p, int *q) {
  int t = *p;
  *p = *q;
  *q = t;
}

void bsort(int data[], int sz) {
  int sorted, i;

  do {
    sorted = 1;
    for (i = 0; i < sz - 1; i++)
      if (data[i] > data[i+1]) {
	sorted = 0;
	swap(&data[i], &data[i+1]);
      }
  } while (sorted != 1);
}
