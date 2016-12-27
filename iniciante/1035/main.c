/*
Teste de Seleção 1
https://www.urionlinejudge.com.br/judge/pt/problems/view/1035
*/

#include <stdio.h>

int main (void) {
  int a, b, c, d;

  scanf("%d %d %d %d", &a, &b, &c, &d);

  if (b > c
    && d > a
    && (c + d) > (a + b)
    && c > 0
    && d > 0
    && (a % 2) == 0) {
    printf("Valores aceitos\n");
  }
  else {
    printf("Valores nao aceitos\n");
  }

  return 0;
}
