//Algoritmo de ordenamiento burbuja
//Este algoritmo es estable ya que si son iguales los dos numeros del arreglo
//la funcion swap no los itercambia.
void bsort(int data[], int sz) {
	int sorted, i;

	do {
		sorted = 1;
		for (i = 0; i < sz - 1; i++)
			if (data[i] > data[i+1]){
				sorted = 0;
				swap(&data[i], &data[i+1]);
			}
	} while (sorted != 1);
}

//Algoritmo de ordenamiento por seleccion
//este algoritdo de ordenamiento es estable, sucede lo mismo que en el anterior.
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

//Algoritmo de ordenamiento por insercion
//Este algoritmo de ordenamiento es estable, sucede lo mismo que los anteriores.
void isort(int arr[], int sz) {
  for(int i = 0; i <  sz ; i++){
    int prev = i, j = i + 1;
    while(prev > -1 && j < sz && arr[prev] > arr[j])
      swap(&arr[prev--],&arr[j--]);
  }
}
