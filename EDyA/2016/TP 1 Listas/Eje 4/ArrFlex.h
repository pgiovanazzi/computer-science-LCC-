#ifndef __ArrFlex_H__
#define __ArrFlex_H__

typedef void (*VisitorFuncInt) (int data, void *extra_data);

#define MAX 100

typedef struct _ArrFlex{
	int data[MAX];
	int len;
} ArrFlex;

typedef ArrFlex *AF;

#define af_data(arr,i)	(arr)->data[(i)]
#define af_len(arr)		(arr)->len 
#define af_nil()			NULL

/**
 * Agrega un elemento al final del ultimo elemento del arreglo.
 */
AF af_append(AF arr,int data);

/**
 * Agrega un elemento al arreglo en el i-esimo elemento.
 */
AF af_insert(AF arr,int data, int idx);

/**
 * Destruccion del arreglo.
 */
void af_destroy(AF arr);

/**
 * Reccorre el arreglo, con una funcion pasada.
 */
void af_foreach(AF arr, VisitorFuncInt visit, void *extra_data);

#endif /*__ArrFlex_H__*/
