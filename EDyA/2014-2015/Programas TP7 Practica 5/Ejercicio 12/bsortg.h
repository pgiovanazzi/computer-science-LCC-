#ifndef __BSORT_H__
#define __BSORT_H__

typedef enum {ORO = 1,COPA,BASTO,ESPADA} PALO; 
typedef struct _carta{
	int num;
	PALO palo;
} Carta;

typedef int (*CmpFunc)(Carta , Carta );

void bsortg(void* [], int, CmpFunc);

#endif /* __BSORT_H__ */
