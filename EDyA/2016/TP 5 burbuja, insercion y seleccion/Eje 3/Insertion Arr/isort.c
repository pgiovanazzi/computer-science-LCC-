#include "isort.h"

void swap(int *a, int *b){
  int t = *a;
  *a = *b;
  *b = t;
}

void isort(int arr[], int sz) {
  for(int i = 0; i <  sz ; i++){
    int prev = i, j = i + 1;
    while(prev > -1 && j < sz && arr[prev] > arr[j])
      swap(&arr[prev--],&arr[j--]);
  }
}
