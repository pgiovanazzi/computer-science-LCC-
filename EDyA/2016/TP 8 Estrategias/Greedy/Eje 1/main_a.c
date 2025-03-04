#include <stdio.h>
#include <stdlib.h>

#define DISK    10

typedef struct _files{
  int num;
  int sz;
} files;

int cmpFiles(const void *p, const void *q){
  files *sz1 = (files *)p;
  files *sz2 = (files *)q;

  return sz1->sz - sz2->sz;
}

void solve(files f[], int sz){
  int acumSz = 0;
  int totalFiles = 0;
  int previous_sz;

  printf("Archivos seleccionados: ");

  qsort(f, sz, sizeof(files), cmpFiles);

  acumSz += f[0].sz;
  previous_sz = 0;

  for (int i = 1; i < sz; i++) {
    if(DISK < acumSz) break;
    acumSz += f[i].sz;
    printf("%d\t", f[previous_sz++].num);
  }
  totalFiles = previous_sz;
  printf("\nTotal de archivos en disco: %d\n", totalFiles);
}

int main(int argc, char const *argv[]) {
  int sz;
  files *setFiles;

  scanf("%d", &sz);
  setFiles = malloc(sizeof(files)*sz);

  for (int i = 0; i < sz; i++) {
    scanf("%d", &setFiles[i].sz);
    setFiles[i].num = i;
  }

  solve(setFiles, sz);

  return 0;
}
