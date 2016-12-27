/*
Divisores I
https://www.urionlinejudge.com.br/judge/pt/problems/view/1157
*/

#include <stdio.h>

void imprimirDivisores(int n);

int main (void) {
    int n;

    scanf("%d", &n);

    imprimirDivisores(n);

    return 0;
}

void imprimirDivisores(int n) {
    int i;

    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d\n", i);
        }
    }
}
