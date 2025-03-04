typedef int (*CmpFunc)(void *, void *);

void bbsort(int data[], int sz);

void bbsortg(void *data, int sz, CmpFunc cmp, unsigned int sze);
