#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b)	(((a) > (b)) ? (a) : (b))
#define LEN(arr)	sizeof(arr)/sizeof(arr[0])

typedef struct {
	int weight;
	int value;
}	object;

//recursive futction
int solve_m(int w, object item[], int sz) {
	//caso base
	if (sz == 0 || w == 0)
		return 0;

	//caso general
	if (item[sz-1].weight > w)
		return solve_m(w, item, sz-1);
	else
		return MAX(item[sz-1].weight + solve_m(w - item[sz-1].weight, item, sz-1), solve_m(w, item, sz-1));
}

//iterative futction
int solve_mi(int w, object item[], int sz) {
	int i, j;
	int table[sz+1][w+1];

	//construyendo la table[][]
	for (i = 0; i <= sz; i++) {
		for (j = 0; j <= w; j++){
			if (i == 0 || w == 0)
				table[i][j] = 0;
			else if (item[i-1].weight <= w)
				table[i][j] = MAX(item[i-1].value + table[i-1][j-item[i-1].weight], table[i-1][j]);
			else
				table[i][j] = table[i-1][j];
		}
	}
	return table[sz][w];
}

int main(void) {
	object items[] = {{30, 30}, {60, 20}, {5, 10}};
	int W = 39, sz = LEN(items);

  printf("Capacidad adquirida maxima: %d Kgs. de %d Kgs.\n", solve_m(W, items, sz), W);

  return 0;
}
