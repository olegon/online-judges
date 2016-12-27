/*
Cálculo Simples
https://www.urionlinejudge.com.br/judge/pt/problems/view/1010
*/

#include <stdio.h>

int main (void) {
  int codigo, quantidade;
  int i;
  double valor;
  double total = 0;


  for (i = 0; i < 2; i++) {
    scanf("%d %d %lf", &codigo, &quantidade, &valor);
    total += quantidade * valor;
  }

  printf("VALOR A PAGAR: R$ %.2f\n", total);

  return 0;
}
