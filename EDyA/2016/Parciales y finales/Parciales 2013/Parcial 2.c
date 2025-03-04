// 1 a)
typedef void (*VisitorFuncIntPtr)(int *data, void *extra_data);
// b)
void btree_foreach_level(BTree *tree, VisitorFuncInt visit, void *extra_data){
	SLQueue queue = slqueue_create();
	queue = slqueue_enqueue(queue,tree);
	while (!queue_is_empty(queue)) {
		visit(&btree_data((BTree *)slqueue_front(queue)),extra_data);
		if( btree_left((BTree *)slqueue_front(queue)) != NULL )
			queue = slqueue_enqueue(queue, btree_left((BTree *)slqueue_front(queue)));
		if( btree_right((BTree *)slqueue_front(queue)) != NULL )
			queue = slqueue_enqueue(queue, btree_right((BTree *)slqueue_front(queue)));
		queue = slqueue_dequeue(queue);
	}
}
// c)
void remplace(int *data, void *extra_data){
	*data = *(int *)extra_data;
}

void btree_remplace( BTree *root, int data){
	btree_foreach(root, remplace, &data );
}
// o que es lo mismo
void remplace(int *data, void *extra_data){
	*data = (int *)extra_data;
}

void btree_remplace( BTree *root, int data){
	btree_foreach(root, remplace, (int *)data );
}

/*
	hash: K -> [0, R-1]nat
	donde K son las claves de tipo void * y retorna un entero sin signo de 0 a R-1 donde R es la 	cantidad de cubetas.
	Sirve para almacenar elementos con un dato asociado y permite de manera eficiente la busqueda
	de dichos elementos (claves) a travez de una funcion hash.
	Las condiciones ideales son:
	-Sea facil de computar.
	-Distribur las claves de manera uniforme entre todas las cubetas.
*/

/* 3 a) El primero es un heap
		  El segundo no es un heap
		  El tercero no es un heap
		  El cuarto no es un heap
	  b)		heap:
	  	       2
	  	   9		 8
	  	10  12  11				
	  	arr: [ 2, 9, 8, 10, 12, 11 ]
	  	
	  c)		heap:
	  			 9
	  		10		11
	   12
	   arr: [ 9, 10, 11, 12 ]
