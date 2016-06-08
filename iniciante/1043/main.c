#include <stdio.h>

int isTriangulo(double a, double b, double c);
double perimetroDoTriangulo(double a, double b, double c);
double areaDoTrapezio(double b1, double b2, double h);

int main (void) {
  double a, b, c;

  scanf("%lf %lf %lf", &a, &b, &c);

  if (isTriangulo(a, b, c)) {
    printf("Perimetro = %.1f\n", perimetroDoTriangulo(a, b, c));
  }
  else {
    printf("Area = %.1f\n", areaDoTrapezio(a, b, c));
  }

  return 0;
}

int isTriangulo(double a, double b, double c) {
  return a < b + c && b < a + c && c < a + b;
}

double perimetroDoTriangulo(double a, double b, double c) {
  return a + b + c;
}

double areaDoTrapezio(double b1, double b2, double h) {
  return (b1 + b2) * h / 2;
}
