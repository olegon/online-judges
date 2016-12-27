/*
Lanche
https://www.urionlinejudge.com.br/judge/pt/problems/view/1038
*/

#include <stdio.h>

int main (void) {
  double valores[] = { 4, 4.5, 5, 2, 1.5 };
  int codigo, quantidade;

  scanf("%d %d", &codigo, &quantidade);

  printf("Total: R$ %.2f\n", valores[codigo - 1] * quantidade);

  return 0;
}
