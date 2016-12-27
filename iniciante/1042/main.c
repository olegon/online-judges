/*
Sort Simples
https://www.urionlinejudge.com.br/judge/pt/problems/view/1042
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int menor(const void *a, const void *b);

int main (void) {
  int ordenado[SIZE],
      original[SIZE],
      i;

  for (i = 0; i < 3; i++) {
    scanf("%d", &original[i]);
    ordenado[i] = original[i];
  }

  qsort(ordenado, SIZE, sizeof(int), menor);

  for (i = 0; i < 3; i++) {
    printf("%d\n", ordenado[i]);
  }

  printf("\n");

  for (i = 0; i < 3; i++) {
    printf("%d\n", original[i]);
  }

  return 0;
}


int menor(const void *a, const void *b) {
  return *(int*)a - *(int*)b;
}
