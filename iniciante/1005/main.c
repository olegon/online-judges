#include <stdio.h>

int main (void) {
  double a, b;

  scanf("%lf %lf", &a, &b);

  double f = (a * 3.5 + b * 7.5) / 11.0;
  f = f >= 10.0 ? 10.0 : f;

  printf("MEDIA = %.5f\n", f);

  return 0;
}
