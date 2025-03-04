#include <stdio.h>
#include <stdlib.h>

#define DISK  10

typedef struct _files{
  int num;
  int sz;
} files;

int cmpFiles(const void *x, const void *y){
  return ((files *)y)->sz - ((files *)x)->sz;
}

void solve(files f[], int len){
  int acumSz = 0, totalFiles = 0;

  qsort(f, len, sizeof(files), cmpFiles);

  printf("Los archivos elejidos son: ");

  for (int i = 0; i < len; i++) {
    if( DISK  < acumSz + f[i].sz ) continue;
    acumSz += f[i].sz;
    totalFiles++;
    printf("\t%d\t", f[i].num);
  }
  printf("\nTotal de archivos en disco: %d\n", totalFiles );
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
