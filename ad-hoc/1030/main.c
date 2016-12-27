/*
A Lenda de Flavious Josephus
https://www.urionlinejudge.com.br/judge/pt/problems/view/1030
*/

#include <stdio.h>

#define SIZE 10000

int calc(int n, int k);

int main (void) {
  int nc, i;
  int n, k, j, next, skip;

  int pessoas[SIZE];

  scanf("%d", &nc);

  for (i = 0; i < nc; i++) {
    scanf("%d %d", &n, &k);

    printf("Case %d: %d\n", i, calc(n, k));
  }

  return 0;
}

int calc(int n, int k) {
  int div, mod;

  div = n / k;
  mod = n % k;

  printf("%d %d\n", div, mod);
  fflush(stdout);

  if (n == 1) {
    return 1;
  }
  else {
    return calc(n - div, k) + mod;
  }
}
