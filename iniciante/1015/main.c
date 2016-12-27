/*
Distância Entre Dois Pontos
https://www.urionlinejudge.com.br/judge/pt/problems/view/1015
*/

#include <stdio.h>
#include <math.h>

int main (void) {
  double x1, y1;
  double x2, y2;
  
  scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
  
  printf("%.4f\n", sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
  
  return 0;
}
