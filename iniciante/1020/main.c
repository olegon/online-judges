/*
Idade em Dias
https://www.urionlinejudge.com.br/judge/pt/problems/view/1020
*/

#include <stdio.h>

int main (void) {
  int dias;
  int quantidade;
  
  scanf("%d", &dias);
  
  printf("%d ano(s)\n", dias / 365);
  dias = dias % 365;
  
  printf("%d mes(es)\n", dias / 30);
  dias = dias % 30;
  
  printf("%d dia(s)\n", dias);  
  
  return 0;
}
