/*
Carrega ou não Carrega?
https://www.urionlinejudge.com.br/judge/pt/problems/view/1026
*/

#include <stdio.h>

int main (void) {
  unsigned int a, b;

  while (scanf("%u %u", &a, &b) != EOF) {
    // xor
    printf("%u\n", a ^ b);
  }

  return 0;
}
