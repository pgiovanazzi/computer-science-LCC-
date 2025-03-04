/* 
	1
		a)
		Ordenar los n clientes de forma acendente en funcion del tiempo de espera de cada cliente.
	
	3
	a)
	El funcionamiento del algoritmo margesort esta basado en la estrategia divide and Conquer.
	Dado un arreglo y su longitud este se divide en dos subarreglos por la mitad, teniendo en cuenta la nueva 
	longitud de cada arreglo, este proceso se retpite recursivamente hasta tener un elemento en cada subarreglo, 
	luego se van comparando los elementos de cada arreglo poniendolos en un arreglo nuevo de menor a mayor. Como 
	este algoritmo tiene una naturaleza recursiva al terminar el stack se tendra el arreglo con todos los elementos ordenados.

	b)
	La complejidad computacional es Cmargesort(n) = 2Cmargesort(n/2) + O(n)
	por el teorema maestro se tiene
	a = 2, b = 2
	f(n) tiene una complejidad de O(n) por lo que c = 1  y k = 0
	por lo que c = log en base b de a = 1 por lo tanto del caso 2 del teorema maestro
	Cmargesort(n) = O(n log n)
 */