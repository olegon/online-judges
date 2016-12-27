/*
Figurinhas
https://www.urionlinejudge.com.br/judge/pt/problems/view/1028
*/

#include <stdio.h>

int euclidianMDC(int a, int b);

int main (void) {
  int n, i;
  int f1, f2;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d %d", &f1, &f2);

    printf("%d\n", euclidianMDC(f1, f2));
  }

  return 0;
}

int euclidianMDC(int a, int b) {
  if (b == 0) {
    return a;
  }
  else {
    return euclidianMDC(b, a % b);
  }
}
