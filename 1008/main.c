/*
Salário
https://www.urionlinejudge.com.br/judge/pt/problems/view/1008
*/

#include <stdio.h>

int main (void) {
  int number, hours;
  double salaryPerHour;

  scanf("%d %d %lf", &number, &hours, &salaryPerHour);

  printf("NUMBER = %d\n", number);
  printf("SALARY = U$ %.2f\n", hours * salaryPerHour);

  return 0;
}
