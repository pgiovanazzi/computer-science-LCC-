int elem(int *q, int l, int *b)
{
	int i, cont = 0;
	for(i = 0; i < l; i++)
		if(q[i] == *b)
			return 1;
	return 0;
}

int are_permutable(int *a, int *b, int l)
{
	int i,j, cont = 0;
	for(i = 0; i < l; i++)
		if(elem(b, l, &a[i]))
			cont++;
	return cont == l;
}