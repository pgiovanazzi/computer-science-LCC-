#ifndef __QSORT_H__
#define __QSORT_H__

typedef enum {
  PIVOTE_ALEATORIO,
  PIVOTE_FINAL,
  PIVOTE_CENTRAL,
  PIVOTE_MEDIANA
} EleccionPivote;

void qsort_(int arr[], int init, int last, EleccionPivote ep);

#endif /* __QSORT_H__ */