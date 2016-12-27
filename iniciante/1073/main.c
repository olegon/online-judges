/*
Quadrado de Pares
https://www.urionlinejudge.com.br/judge/pt/problems/view/1073
*/

#include <stdio.h>

int main (void) {
    int n,
        i;

    scanf("%d", &n);

    n++;

    for (i = 2; i < n; i += 2) {
        printf("%d^2 = %d\n", i, i * i);
    }

    return 0;
}
