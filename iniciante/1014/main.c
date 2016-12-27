/*
Consumo
https://www.urionlinejudge.com.br/judge/pt/problems/view/1014
*/

#include <stdio.h>

int main (void) {
  int distancia;
  double combustivel;
  
  scanf("%d %lf", &distancia, &combustivel);
  
  printf("%.3f km/l\n", distancia / combustivel);
  
  return 0;
}
