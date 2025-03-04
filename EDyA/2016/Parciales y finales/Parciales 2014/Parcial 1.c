/* 
	1)

	XStack *xstack_crete()
	{
		XStack *xs = malloc(sizeof(XStack));
		xs->q1 = xqueue_create();
		xs->q2 = xqueue_create();
		return xs;
	}

	void xstack_push(XStack *xs, int e)
	{
		xqueue_enqueue(xs->q1, e);
	}

	void xstack_pop(XStack *xs)
	{
		while( xs->q1->next )
		{
			xqueue_enqueue(xs->q2, xs->q1->data );
			xqueue_dequeue(xs->q1);
		}
		xqueue_dequeue(xs->q1);
		xs->q1 = NULL;
		while( xs->q2 )
		{
			xqueue_enqueue(xs->q1, xs->q2->data);
			xqueue_dequeue(xs->q2);
		}
		xs->q2 = NULL;
	}

	int xstack_is_empty(XStack *xs)
	{
		if(xs->q1) return 0;
		return 1;
	}

	2)
	a) int hash(unsigned int dni, int sz)
	{
		return dni % sz;
	}
	
	1 - Facil de computar
	2 - Distribuir las claves de manera uniforme entre todas las cubetas

	Es aceptable porque cumple con los dos puntos anteriores.

	b)
	int main()
	{
		int dni1 = 18181612, dni2 = 18181615, dni3 = 12181612;
		char name1[] = "Espinosa Ricardo", name2[] = "Perez Manuel", name3[] = "Martı́nez Juan";

		Hashtable *ht = hashtable_create(hash, 10);

		hashtable_insert(&dni1,name1);
		hashtable_insert(&dni2,name2);
		hashtable_insert(&dni3,name3);

		return 0;
	}

	c)

		[18181612][Espinosa Ricardo]  i = dni1 % 10;
		[18181615][Perez Manuel]  i = dni2 % 10;
		[12181612][Martı́nez Juan]  i = dni3 % 10;

	3) a, b, c, ya estan echos en el parcial 2013

	4)
	void printIntAndFindMin(int data, void *extra_data)
	{
		printf("%d ", data);
		if ( data < *extra_data )
			*extra_data = data;
	}
	int *min = malloc(sizeof(int));
	*min = tree->data;
	btree_foreach(tree,printIntAndFindMin, min);

 */