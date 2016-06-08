#include <stdio.h>

void sum(int n1, int d1, int n2, int d2);
void sub(int n1, int d1, int n2, int d2);
void mult(int n1, int d1, int n2, int d2);
void div(int n1, int d1, int n2, int d2);
void simplificar(int n, int d);

int main (void) {
  int n, i;
  int n1, d1, n2, d2;
  char op;
  
  scanf("%d", &n);
  
  for (i = 0; i < n; i++) {
    scanf("%d / %d %c %d / %d", &n1, &d1, &op, &n2, &d2);
    
    if      (op == '+') sum(n1, d1, n2, d2);
    else if (op == '-') sub(n1, d1, n2, d2);
    else if (op == '*') mult(n1, d1, n2, d2);
    else if (op == '/') div(n1, d1, n2, d2);    
  }
  
  return 0;
}

// Soma: (N1*D2 + N2*D1) / (D1*D2)
void sum(int n1, int d1, int n2, int d2) {
  int n = n1 * d2 + n2 * d1;
  int d = d1 * d2;
  
  printf("%d/%d = ", n, d);
  simplificar(n, d);  
}

// Subtração: (N1*D2 - N2*D1) / (D1*D2)
void sub(int n1, int d1, int n2, int d2) {
  int n = n1 * d2 - n2 * d1;
  int d = d1 * d2;
  
  printf("%d/%d = ", n, d);
  fflush(stdout);
  simplificar(n, d);
}

// Multiplicação: (N1*N2) / (D1*D2)
void mult(int n1, int d1, int n2, int d2) {
  int n = n1 * n2;
  int d = d1 * d2;
  
  printf("%d/%d = ", n, d);
  simplificar(n, d);
}

// Divisão: (N1/D1) / (N2/D2), ou seja (N1*D2)/(N2*D1)
void div(int n1, int d1, int n2, int d2) {
  int n = n1 * d2;
  int d = n2 * d1;
  
  printf("%d/%d = ", n, d);
  simplificar(n, d);
}

void simplificar(int n, int d) {
  int maior = n > d ? n : d;
  int i;
  
  for (i = maior; i > 0; i--) {
    if (n % i == 0 && d % i == 0) break;
  }  
  
  printf("%d/%d\n", n / i, d / i);
}

