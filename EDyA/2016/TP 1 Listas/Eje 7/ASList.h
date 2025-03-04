#ifndef __ASList_H__
#define __ASList_H__

typedef void (*VisitorFuncInt) (int data, void *extra_data);

static int STORE = 4;

typedef struct _ArrSList{
	int *data;
	int len;
} ArrSList;

typedef ArrSList *ASList;

#define aslist_data(l,i)			(l)->data[(i)]
#define aslist_len(l)		  		(l)->len
#define aslist_nil()			  	NULL

/**
 * Crea una lista.
 */
 ASList aslist_create();

/**
 * Agrega un elemento al final del ultimo elemento del lista.
 */
ASList aslist_append(ASList list,int data);

/**
 * Agrega un elemento a la lista en el i-esimo elemento.
 */
ASList aslist_insert(ASList list,int data, int idx);

/**
 * Destruccion del lista.
 */
void aslist_destroy(ASList list);

/**
 * Reccorre la lista, con una funcion pasada.
 */
void aslist_foreach(ASList list, VisitorFuncInt visit, void *extra_data);

#endif /*__ASList_H__*/
