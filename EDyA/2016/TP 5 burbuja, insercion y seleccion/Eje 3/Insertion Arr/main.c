#include <stdio.h>
#include "isort.h"

#define NELEMS(a)   (sizeof(a) / sizeof(int))

void printArr(int arr[], int sz){
  printf("< ");
  for (size_t i = 0; i < sz; i++) {
    printf("%d, ", arr[i]);
  }
  printf(" >\n");
}

int main(int argc, char const *argv[]) {

  int arr[] = { 7,5,4,1,8,0,10,6 };

  printArr(arr,NELEMS(arr));

  printf("isort(arr,sz): ");
  isort(arr,NELEMS(arr));
  printArr(arr,NELEMS(arr));

  return 0;
}
