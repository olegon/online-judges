#include <stdio.h>

int main (void) {
  double v;

  scanf("%lf", &v);

  if (v < 0) {
    printf("Fora de intervalo\n");
  }
  else if (v <= 25) {
    printf("Intervalo [0,25]\n");
  }
  else if (v <= 50) {
    printf("Intervalo (25,50]\n");
  }
  else if (v <= 75) {
    printf("Intervalo (50,75]\n");
  }
  else if (v <= 100) {
    printf("Intervalo (75,100]\n");
  }
  else {
    printf("Fora de intervalo\n");
  }

  return 0;
}
