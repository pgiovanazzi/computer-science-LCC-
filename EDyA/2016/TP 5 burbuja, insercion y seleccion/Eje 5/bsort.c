void swap(int *p, int *q){
	int t = *p;
	*p = *q;
	*q = t;
}

void bsort(int data[], int sz) {
	int j, i;
	for(j = 0; j < sz; j++)
		for (i = 0; i < sz - 1; i++)
			if (data[i] > data[i+1])
				swap(&data[i], &data[i+1]);
}
