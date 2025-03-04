/************************************************
   Tester para SList. La siguiente es la salida esperada para una
  implementación correcta de SList. Si su salida difiere, lea las
  notas abajo!
   También tener en mente que una salida igual a la siguiente no
  es garantía de una implementación correcta. De hecho, no se prueban
  todas las funciones.

 -----
	len(l1) = 10
	len(l2) = 12
	len(l3) = 9

	l1 = <48, 43, 21, 34, 0, 61, 65, 28, 39, 96, >
	l2 = <94, 89, 21, 71, 28, 59, 14, 22, 62, 2, 0, 71, >
	l3 = <96, 66, 30, 79, 72, 47, 99, 81, 11, >

	l1 ++ l2 = <48, 43, 21, 34, 0, 61, 65, 28, 39, 96, 94, 89, 21, 71, 28, 59, 14, 22, 62, 2, 0, 71, >
	l1 ++ [] = <48, 43, 21, 34, 0, 61, 65, 28, 39, 96, >
	[] ++ l2 = <94, 89, 21, 71, 28, 59, 14, 22, 62, 2, 0, 71, >

	l1 <inter> l2 = <28, 0, 21, >
	l1 <inter> l3 = <96, >

	sort(l1) = <0, 21, 28, 34, 39, 43, 48, 61, 65, 96, >

 -----

************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "SList.h"
#include "Eje3.h"

static void print_int (int data, void *extra_data){
	printf("%d, ", data);
}

static void printlist(SList *l) {
	printf("<");
	slist_foreach(l, print_int, NULL);
	printf(">\n");
}

int icmp(int x, int y) {
	return x-y;
}

int compa(const void *a, const void *b){
	return ( *(int*)a - *(int*)b );
}

int mod5(int x, int y) {
	return (x-y)%5 == 0;
}

SList * clonar(SList *l) {
	SList *ret = NULL;

	for(; l != NULL; l = slist_next(l))
		ret = slist_append(ret, slist_data(l));

	return ret;
}

int main(int argc, char *argv[])
{
	SList *l1=NULL, *l2=NULL, *l3=NULL, *l4=NULL, *l5 = NULL;
	int i;

	l1 = add_beg(l1, 96);
	l1 = add_beg(l1, 39);
	l1 = add_beg(l1, 28);
	l1 = add_beg(l1, 65);
	l1 = add_beg(l1, 61);
	l1 = add_beg(l1, 00);
	l1 = add_beg(l1, 34);
	l1 = add_beg(l1, 21);
	l1 = add_beg(l1, 43);
	l1 = add_beg(l1, 48);

	l2 = add_beg(l2, 71);
	l2 = add_beg(l2, 00);
	l2 = add_beg(l2, 02);
	l2 = add_beg(l2, 62);
	l2 = add_beg(l2, 22);
	l2 = add_beg(l2, 14);
	l2 = add_beg(l2, 59);
	l2 = add_beg(l2, 28);
	l2 = add_beg(l2, 71);
	l2 = add_beg(l2, 21);
	l2 = add_beg(l2, 89);
	l2 = add_beg(l2, 94);

	l3 = add_beg(l3, 11);
	l3 = add_beg(l3, 81);
	l3 = add_beg(l3, 99);
	l3 = add_beg(l3, 47);
	l3 = add_beg(l3, 72);
	l3 = add_beg(l3, 79);
	l3 = add_beg(l3, 30);
	l3 = add_beg(l3, 66);
	l3 = add_beg(l3, 96);

	printf("len(l1) = ");length(l1);puts("");
	printf("len(l2) = ");length(l2);puts("");
	printf("len(l3) = ");length(l3);
	puts("");

	printf("l1 = "); print(l1);
	printf("l2 = "); print(l2);
	printf("l3 = "); print(l3);
	puts("");

	printf("l1 ++ [] = ");print(concat(l1,NULL,l4));
	printf("[] ++ l2 = ");print(concat(NULL,l2,l4));
	printf("l1 ++ l2 = ");print(concat(l1,l2,l4));
	puts("");

	printf("62 esta en l2? ");contais(l2,62);
	printf("62 esta en l3? ");contais(l3,62);
	printf("62 esta en l1? ");contais(l1,62);
	puts("");

	printf("l1 <inter> l2 = "); print(intersect(l1, l2, l5));
	printf("l1 <inter> l3 = "); print(intersect(l1, l3, l5));
	puts("");


	printf("sort(l1) = "); print(sort(l1));
	puts("");

	return 0;
}

