#include <stdlib.h>
#include <time.h>
#include "qsort.h"

void swap(int *a, int *b){
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int data[], int init, int last, type_part tp){
  int l = init, r = last, pivot;
  if (tp == 0) {
    srand(time(NULL));
    int idxPivotTaken = rand()%(last + 1 - init) + init;
    pivot = data[idxPivotTaken];
  }
  else if (tp == 1){
    pivot = data[last];
  }
  else if (tp == 2)
    pivot = data[(init + last)/2];
  else
    pivot = data[(init + (init + last)/2 + last)/3];

  while (l < r) {
    while (data[l] < pivot && l < r)
      l++;
    while (data[r] > pivot)
      r--;

    if (l <= r)
      swap(&data[r], &data[l]);
  }
  return r;
}

void qsort_(int data[], int init, int last, type_part tp, int *v){
  int pivot;s
  (*v)++;

  if (init < last) {
    pivot = partition(data, init, last, tp);
    qsort_(data, init, pivot-1, tp, v);
    qsort_(data, pivot+1, last, tp, v);
  }
}
