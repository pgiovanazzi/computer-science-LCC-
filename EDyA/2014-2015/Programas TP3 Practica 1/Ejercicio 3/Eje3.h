#ifndef __EJE3_H__
#define __EJE3_H__

//Crea list.
SList *create(int data, SList *next);

//Destruye list.
void  destroy(SList *list);

//Imprime el contenido actual de la list.
void  print(SList *list);

//Agrega elem al final de la list.
SList *add_end(SList *list, int elem);

//Agrega elem al principio de la list.
SList *add_beg(SList *list, int elem);

//Agrega elem a la list en la posición pos
SList *add_pos(SList *list, int elem, unsigned int pos);

//Imprime la longitud de una list.
void length(SList *list);

//Concatena l1 y l2, crea l3 con el resultado.
SList *concat(SList *l1, SList *l2, SList *l3);

//Elimina de la list el elemento en la posición pos.
SList *removes(SList *list, unsigned int pos);

//Imprime "SI" si la list contiene a elem, "NO" sino.
void contais(SList *list, int elem);

//Imprime las posiciones en las que está elem.
void indexs(SList *list, int elem);

//Crea l3 con la intersección de l1 y l2.
SList *intersect(SList *l1, SList *l2, SList *l3);

//Ordena los elementos de la list de menor a mayor.
SList *sort(SList *list);

#endif /* __SLIST_H__ */
