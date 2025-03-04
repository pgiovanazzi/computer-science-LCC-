static void swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void ssort(int datos[], int tam) {
	unsigned mayor;
	for (unsigned i = tam - 1; i > 0; i--) {
		mayor = 0;
		for (unsigned j = 1; j <= i; j++)
			if (datos[mayor] < datos[j])
				mayor = j;
		swap(&datos[i], &datos[mayor]);
	}
}