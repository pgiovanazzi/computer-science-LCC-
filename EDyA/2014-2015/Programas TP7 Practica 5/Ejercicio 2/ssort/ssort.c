void swap(int *p, int *q){
	int t = *p;
	*p = *q;
	*q = t;
}

void ssort(int data[], int sz) {
	int min, i, j;

	for(i = 0; i < sz; i++){
		min = i;
		for(j = i + 1; j < sz; j++)
			if(data[j] < data[min])
				min = j;
		swap(&data[i], &data[min]);
	}
}
