#include <stdio.h>

#define SWAP(a,b)    {int t = a; a = b; b = t;}
#define LEN(a)       (sizeof(a)/sizeof(*a))

void heapify(int *arr, int sz){
  for (int i = 0; i < sz; i++) {
    int p = i, pp, ch = i;
    int child = 2 * p + 1;
    while ( (arr[p] < arr[child] || arr[p] < arr[child + 1]) && child < sz - 1) {
      if(arr[child] < arr[child + 1] && child + 1 < sz){
        SWAP(arr[child + 1], arr[p]);
        p = child + 1;
      }else{
        SWAP(arr[child], arr[p]);
        p = child;
      }
      child = 2 * p + 1;
      if(child > sz - 1) break;
    }
    if(ch % 2 == 0) pp = (ch-1)/2;
    else pp = ch/2;
    while (arr[ch] > arr[pp] && pp > -1) {
      SWAP(arr[pp], arr[ch]);
      ch = pp;
      if(ch % 2 == 0) pp = (ch-1)/2;
      else pp = ch/2;
    }
  }
}

/************* Otra forma de hacerlo ***************/

#define dad(X)    (((X)-1)/2)

void upper(int *arr, int idx){
  int posDad =  dad(idx);

  if( posDad == idx ) return;

  if( arr[posDad] < arr[idx] ){
    SWAP(arr[posDad], arr[idx]);
    upper(arr, posDad);
  }
  return;
}

void heapify_1(int *arr, int sz){

  for (int i = 0; i < sz; i++) {
    upper(arr, i);
  }
}


int main(int argc, char const *argv[]) {
  int arr[] = {4, 5, 1, 2, 3, 8, 4, 10};

  printf("Arr: < ");
  for (int i = 0; i < LEN(arr); i++) {
    printf("%d, ", arr[i]);
  }
  puts(">");

  heapify_1(arr,LEN(arr));

  printf("heapify(Arr): < ");
  for (int i = 0; i < LEN(arr); i++) {
    printf("%d, ", arr[i]);
  }
  puts(">");

  return 0;
}
