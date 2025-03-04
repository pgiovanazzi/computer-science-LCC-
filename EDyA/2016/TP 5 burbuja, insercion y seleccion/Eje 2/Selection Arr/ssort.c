
void swap(int *a, int *b){
  int t = *a;
  *a = *b;
  *b = t;
}

void ssort(int arr[], int sz){
  for (int i = 0; i < sz; i++) {
    int min = i;
    for (int j = i + 1; j < sz; j++) {
      if(arr[min] > arr[j])
        min = j;
    }
    swap(&arr[i],&arr[min]);
  }
}
