/*
Onda Crítica
https://www.urionlinejudge.com.br/judge/pt/problems/view/1027
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
#define DEBUG 1

typedef struct {
  short x;
  short y;
} COORD;

int compare(const void *a, const void *b);

int main (void) {
  int n, i; 

  COORD coords[SIZE];
 
  
  while (scanf("%d", &n) == 1) {
    /* Ler coordenadas. */
    for (i = 0; i < n; i++) {
      scanf("%hd %hd", &coords[i].x, &coords[i].y);
    }
    
    qsort(coords, n, sizeof(COORD), compare);
  }  
  
  
  return 0;
}

int compare(const void *a, const void *b) {
  return ((COORD*)a)->x - ((COORD*)b)->x;
}

int b(const COORD *coords, size_t start, size_t size) {
  if (start == size) {
    return 0;
  }
  else {
    
  }
  
  return 0;
}

int c(const COORD *coords, size_t start, size_t size) {
  return 0;
}

