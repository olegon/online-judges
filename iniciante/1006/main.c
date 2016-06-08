#include <stdio.h>

int main (void) {
  double a, b, c;

  scanf("%lf %lf %lf", &a, &b, &c);

  double f = a * 0.2 + b * 0.3 + c * 0.5;
  f = f >= 10.0 ? 10.0 : f;

  printf("MEDIA = %.1f\n", f);

  return 0;
}
