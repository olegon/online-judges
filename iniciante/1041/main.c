#include <stdio.h>

int main (void) {
  double x1, y1;
  
  scanf("%lf %lf", &x1, &y1);
  
  if (x1 < 0) {
    if (y1 < 0) {
      printf("Q3\n");
    }
    else if (y1 == 0) {
      printf("Eixo X\n");
    }
    else {
      printf("Q2\n");
    }
  }
  else if (x1 == 0) {
    if (y1 == 0) {
      printf("Origem\n");
    }
    else {
      printf("Eixo Y\n");
    }
  }
  else {
    if (y1 < 0) {
      printf("Q4\n");
    }
    else if (y1 == 0) {
      printf("Eixo X\n");
    }
    else {
      printf("Q1\n");
    }
  }
  
  return 0;
}
