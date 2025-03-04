#include <stdlib.h>
#include <string.h>
#include "bbsort.h"

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    return;
}

void bbsort(int data[], int sz){
    int i;
    int sorted;
    do {
        sorted = 1;
        for (i = 0; i < sz - 1; i++)
            if (data[i] > data[i+1]) {
                sorted = 0;
                swap(&data[i], &data[i+1]);
            }
    } while(sorted != 1);
}

void swapg(void *l, void *r, unsigned int sze)
{
    void *temp = malloc(sze);
    memcpy(temp,r,sze); 
    memcpy(r,l,sze);
    memcpy(l,temp,sze);
    free(temp);
    return;
}

void bbsortg(void *data, int sz, CmpFunc cmp, unsigned int sze){
    int i;
    int sorted;
    do {
        sorted = 1;
        for (i = 0; i < sz - 1; i++)
            if (cmp(data + i * sze, data + (i+1) * sze) > 0) {
                sorted = 0;
                swapg(data + i * sze, data + (i+1) * sze, sze);
            }
    } while(sorted != 1);
}
