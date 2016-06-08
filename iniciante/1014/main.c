#include <stdio.h>

int main (void) {
  int distancia;
  double combustivel;
  
  scanf("%d %lf", &distancia, &combustivel);
  
  printf("%.3f km/l\n", distancia / combustivel);
  
  return 0;
}
