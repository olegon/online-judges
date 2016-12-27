/*
Salário com Bônus
https://www.urionlinejudge.com.br/judge/pt/problems/view/1009
*/

#include <stdio.h>

#define NAME_SIZE 64

int main (void) {
  char nome[NAME_SIZE];
  double salary, sells;

  scanf("%s %lf %lf", nome, &salary, &sells);

  printf("TOTAL = R$ %.2f\n", salary + sells * 0.15);

  return 0;
}
