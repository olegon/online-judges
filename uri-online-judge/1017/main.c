/*
Gasto de Combustível
https://www.urionlinejudge.com.br/judge/pt/problems/view/1017
*/

#include <stdio.h>

#define CONSUMO 12

int main (void) {
  double velocidade, tempo;
  
  scanf("%lf %lf", &velocidade, &tempo);
  
  printf("%.3f\n", tempo * velocidade / CONSUMO);
  
  return 0;
}
