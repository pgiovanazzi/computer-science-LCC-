#include <stdio.h>
#include <stdlib.h>

#define MOCILA	20

typedef struct{
	int kilos;
	int price;
	char name[13];
} object;

int cmpPrice(const void *p, const void *q)
{
	object *fst = (object *)p;
	object *snd = (object *)q;

	return snd->price - fst->price;
}

void solve(object items[], int sz) {
	float possible_items = 0.0;
	int i = 0, KilosAct = 0;

	printf("Objetos elegidos: ");

	qsort(items, sz, sizeof(object), cmpPrice);

	for (i = 0; i < sz && KilosAct < MOCILA; i++) {
		if (KilosAct + items[i].kilos <= MOCILA){
			printf("%s ", items[i].name);
			possible_items++;
			KilosAct += items[i].kilos;
		}
		else {
			printf("\nFraccionado: %s ", items[i].name);
			ossible_items++;
			KilosAct += ((MOCILA - KilosAct)/items[i].kilos) * items[i].kilos;
		}
	}

	printf(".\nTotal de items máximos: %.2f.\n", possible_items);
}

int main(int argc, char const *argv[])
{
	int number_of_items, i;
	object *items;

	printf("Ingrese la cantidad de objetos: ");
	scanf("%d", &number_of_items);
	items = malloc(sizeof(object) * number_of_items);

	for(i = 0; i < number_of_items; i++){
		printf("Objetos:\nPeso, precio y nombre:\n");
		scanf("%d%d%s", &items[i].kilos, &items[i].price, &items[i].name);
	}
	
	solve(items, number_of_items);

	return 0;
}