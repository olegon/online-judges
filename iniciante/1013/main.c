#include <stdio.h>

int main (void) {
  int a, b, c;
  
  scanf("%d %d %d", &a, &b, &c);
  
  int m = a > b ? a : b;
  m = m > c ? m : c;
  
  printf("%d eh o maior\n", m);
  
  return 0;
}
