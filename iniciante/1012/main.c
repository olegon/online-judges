/*
Área
https://www.urionlinejudge.com.br/judge/pt/problems/view/1012
*/

#include <stdio.h>

int main (void) {
  const double pi = 3.14159;
  
  double a, b, c;
  
  scanf("%lf %lf %lf", &a, &b, &c);
  
  printf("TRIANGULO: %.3f\n", a * c / 2);
  printf("CIRCULO: %.3f\n", c * c * pi);
  printf("TRAPEZIO: %.3f\n", c * (a + b) / 2);
  printf("QUADRADO: %.3f\n", b * b);
  printf("RETANGULO: %.3f\n", a * b);
  
  return 0;
}
