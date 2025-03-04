#include <stdio.h>
#include <stdlib.h>

int cmpInt(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

void print_number(n)
{
	printf("%d\t", n);
}

int feasible(int n)
{
	int sz = 4;
	int i, aux[sz], dec = n;
	for (i = 0; i < sz; i++) {
		aux[sz - i - 1] = dec % 10;
		dec = dec / 10;
	}

	qsort(aux, sz, sizeof(int), cmpInt);

	for (i = 0; i < sz-1; i++) {
		if ( aux[i] == aux[i+1])
			return 0;
	}
	return 1;
}

void solve(int n)
{
	if (n > 9999)
		return;

	if (feasible(n)) {
		print_number(n);
		solve(n+1);
	}
	else 
		solve(n+1);
}

int main(int argc, char const *argv[])
{
	int number = 1000;

	solve(number);

	return 0;
}