/***  Problema de la mochila fraccional  ***/
#include <stdio.h>
#include <stdlib.h>
// a)
#define BAG_MAX_W 125

typedef struct _item
{
	int num;
	int weight;
	int price;
} item;

int cmpItem(const void *x, const void *y)
{
	float density_a, density_b;
	item *a = (item *)x;
	item *b = (item *)y;
	density_a = (float)a->price / a->weight;
	density_b = (float)b->price / b->weight;
	return (density_b - density_a >= 0) ? 1 : -1;
}

void solve(item objects[], int sz)
{
	int wAcum = 0;
	float pAcum = 0;
	int i = 0;

	printf("Se agrego agregaron los items: ");

	// Ordena los objetos en funcion del valor sobre el peso
	qsort(objects, sz, sizeof(item), cmpItem);

	// Al tomar una fraccion del objeto ¿teniendo el mismo valor?
	while (i < sz && wAcum <= BAG_MAX_W)
	{
		wAcum += objects[i].weight;
		pAcum += objects[i].price;
		printf(" %d:valor %d,\t", objects[i].num, objects[i].price);
		i++;
		// Verifica si el objeto supera el peso maximo
		if (wAcum + objects[i].weight > BAG_MAX_W)
		{
			// Fracciona el objeto y saca una proporcion del valor
			float price_percent = ((float)(BAG_MAX_W - wAcum) / objects[i].weight) * objects[i].price;
			printf("(fraccion de item) %d:valor %.2f\n", objects[i].num, price_percent);
			pAcum += price_percent;
			break;
		}
	}
	printf("Total de valor en la mochila: %.2f\n", pAcum);
}

// b)
/*
  Si utilizamos la estrategia greedy para el problema de la mochila 0-1
  al ordenar los elementos por densidad y tomar o no tomar un bojeto
  no se optiene el resultado optimo global.
*/

int main(int argc, char const *argv[])
{
	item *objs;
	int num_of_items;

	printf("Cantidad de objetos:\n");
	scanf("%d%*c", &num_of_items);
	objs = malloc(sizeof(item) * num_of_items);

	printf("Ingrese de la forma peso-precio:\n");
	printf("           W-V\n");
	printf("          -----\n");
	for (int i = 0; i < num_of_items; i++)
	{	
		printf("Objeto %d: ", i);
		scanf("%d-%d%*c", &objs[i].weight, &objs[i].price);
		objs[i].num = i;
	}

	solve(objs, num_of_items);

	return 0;
}
