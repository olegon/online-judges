/*
Quadrado e ao Cubo
https://www.urionlinejudge.com.br/judge/pt/problems/view/1143
*/

#include <stdio.h>

int main (void) {
    int n,
        i;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("%d %d %d\n", i, i * i, i * i * i);
    }

    return 0;
}
