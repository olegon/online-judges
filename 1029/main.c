/*
Fibonacci, Quantas Chamadas?
https://www.urionlinejudge.com.br/judge/pt/problems/view/1029
*/

#include <stdio.h>

int fib(int n);

int calls = 0;

int main (void) {
  int n, i;
  int x, result;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &x);
    calls = 0;
    result = fib(x);
    printf("fib(%d) = %d calls = %d\n", x, calls - 1, result);
  }

  return 0;
}

int fib(int n) {
  calls++;
  if (n == 0) {
    return 0;
  }
  else if (n == 1) {
    return 1;
  }
  else {
    return fib(n - 1) + fib(n - 2);
  }
}
