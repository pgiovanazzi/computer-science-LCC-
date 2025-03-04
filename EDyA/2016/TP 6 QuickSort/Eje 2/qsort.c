#include "qsort.h"

void swap(int *a, int *b){
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int data[], int init, int last){
  int pivot = data[last], i = init - 1;

  for (int j = init; j < last; j++)
    if(data[j] <= pivot){
      i++;
      swap(&data[i],&data[j]);
    }

  swap(&data[i+1], &data[last]);
  return i+1;
}

void qsort_(int data[], int init, int last){
  int pivot;

  if (init < last) {
    pivot = partition(data, init, last);
    qsort_(data, init, pivot-1);
    qsort_(data, pivot+1, last);
  }
}
