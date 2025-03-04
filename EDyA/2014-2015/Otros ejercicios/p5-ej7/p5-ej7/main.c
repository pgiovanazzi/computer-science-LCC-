#include <stdio.h>
#include "bbsort.h"

int compare(void *x, void *y)
{
    return (*(int*) x - *(int*) y);
}

int main(){
    int data[] = {5,4,2,7,8,9,1,2};
    int i;

    printf("Antes:\n");
    for(i = 0; i < 8-1; i++)
        printf("%d | ",data[i]);
    printf("%d\n--------------------\n",data[7]);

    //bbsort(data,8);
    bbsortg((void*)data,8, compare, sizeof(int));

    printf("Despues:\n");
    for(i = 0; i < 8-1; i++)
        printf("%d | ",data[i]);
    printf("%d\n--------------------\n",data[7]);
    return 0;
}
