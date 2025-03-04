#ifndef __ISORTG_H__
#define __ISORTG_H__

typedef int (*CmpFunc)(void *, void *);

typedef enum {ORO = 1, COPA, BASTO, ESPADA} PALO;

typedef struct _carta {
   int numero;
   PALO p;
} carta;

void isortg(void *data[], int sz, CmpFunc cmp);

#endif
