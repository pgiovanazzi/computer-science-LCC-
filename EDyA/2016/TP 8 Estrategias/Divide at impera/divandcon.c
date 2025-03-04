#include <stdio.h>
#include <stdlib.h>

void combine(int data1[], int sz1, int data2[], int sz2, int r[]) {
  int i = 0, j = 0, k;

  for (k = 0; k < sz1 + sz2; k++) {
    if (i < sz1 && j < sz2 && data1[i] <= data2[j] || i < sz1 && j >= sz2)
      r[k] = data1[i++];
    else if (i < sz1 && j < sz2 && data2[j] <= data1[i] || j < sz2 && i >= sz1)
      r[k] = data2[j++];
  }
}

int *mergesort(int data[], int sz) {
  int *r = malloc(sizeof(int) * sz);
  int mid = sz/2;
  int *sub1, *sub2;

  if (sz == 1) {
    r[0] = data[0];
    return r;
  }

  sub1 = mergesort(data, mid);
  sub2 = mergesort(data + mid, sz - mid);

  combine(sub1, mid, sub2, sz - mid, r);

  free(sub1);
  free(sub2);

  return r;
}

int main(void) {
  int i;
  int lst[] = { 3, 5, 1, 4, 2 };
  int *r = mergesort(lst, 5);

  for (i = 0; i < 5; i++)
    printf("%d\t", r[i]);
  puts("");

	free(r);

  return 0;
}
