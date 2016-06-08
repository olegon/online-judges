#include <stdio.h>

#define PI 3.14159

int main (void) {
  double r;

  scanf("%lf", &r);

  printf("VOLUME = %.3f\n", 4.0 / 3.0 * PI * r * r * r);

  return 0;
}
