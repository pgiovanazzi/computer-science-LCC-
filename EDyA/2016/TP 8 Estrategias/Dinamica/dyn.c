#include <stdio.h>
#include <stdlib.h>

#define MAXN 50
#define MAXK 50

int comb(int n, int k) {
  static int table[MAXN][MAXK] = { 0 };

  if (k == 0 || n == k)
    return 1;

  if (table[n][k] != 0)
    return table[n][k];

  table[n][k] = comb(n - 1, k) + comb(n - 1, k - 1);

  return table[n][k];
}

int comb_(int n, int k) {
  int table[n+1][k+1];
  int i, j;

  for (i = 0; i <= n; i++)
    table[i][0] = 1;

  for (i = 0; i <= n; i++)
    table[i][i] = 1;

  for (i = 0; i <= n; i++)
    for (j = 1; j <= k && j < i; j++)
      table[i][j] = table[i - 1][j - 1] + table[i - 1][j];

  return table[n][k];
}

int main(void) {
  printf("comb(10,9) = %d\n", comb(10, 9));

  return 0;
}
