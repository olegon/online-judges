#include <stdio.h>
#include <math.h>

double getDelta(double a, double b, double c);

int main (void) {
  double a, b, c;

  scanf("%lf %lf %lf", &a, &b, &c);

  if (a <= 0) {
    printf("Impossivel calcular\n");
  }
  else {
    double delta = getDelta(a, b, c);

    if (delta < 0) {
      printf("Impossivel calcular\n");
    }
    else {
      double deltaSquareRoot  = sqrt(delta);
      double r1 = (-b + deltaSquareRoot) / (2 * a);
      double r2 = (-b - deltaSquareRoot) / (2 * a);

      printf("R1 = %.5f\nR2 = %.5f\n", r1, r2);
    }
  }

  return 0;
}

double getDelta(double a, double b, double c) {
  return b * b - 4 * a * c;
}
