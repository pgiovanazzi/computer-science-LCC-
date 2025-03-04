#ifndef __HSORT_H__
#define __HSORT_H__

#define PADRE(X) ((X - 1) / 2)
#define CHILD(X) (X * 2 + 1)

int *hsort(int arr[], unsigned sz);

#endif /* __HSORT_H__ */