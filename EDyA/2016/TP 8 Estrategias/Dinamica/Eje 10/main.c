#include <stdio.h>
#include <stdlib.h>

#define BAG_MAX_W 5

typedef struct _item
{
	int num;
	int peso;
	int valor;
} item;

void solve(item set[], int sz)
{
	int table[sz][BAG_MAX_W];
	
	for (int i = 0; i < sz; i++)
		table[i][0] = 0;
	for (int j = 0; j < BAG_MAX_W; j++)
		table[0][j] = 0;

	for (int i = 1; i < sz; i++)
	{
		for (int j = 1; j < BAG_MAX_W; j++)
		{
			if (set[i].peso <= j)
			{
				if (set[i].valor + table[i - 1][j - set[i].peso] > table[i - 1][j])
					table[i][j] = set[i].valor + table[i - 1][j - set[i].peso];
				else
					table[i][j] = table[i - 1][j];
			}
			else
				table[i][j] = table[i - 1][j];
		}
	}
	printf("El valor maximo que puede tener la mochila es: %d\n", table[sz - 1][BAG_MAX_W - 1]);
}

int main(int argc, char const *argv[])
{
	item *objs;
	int num_of_items;

	printf("Ingrese la cantidad de elementos:\n");
	scanf("%d%*c", &num_of_items);
	objs = malloc(sizeof(item) * num_of_items);
	printf("Ingrese Peso-Valor:\n");
	for (int i = 0; i < num_of_items; i++)
	{
		printf("Objeto nro. %d: ", i);
		scanf("%d-%d%*c", &objs[i].peso, &objs[i].valor);
		objs[i].num = i;
	}

	solve(objs, num_of_items);

	free(objs);

	return 0;
}
