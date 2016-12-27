/*
Notação Científica
https://www.urionlinejudge.com.br/judge/pt/problems/view/1958
*/

#include <stdio.h>

int main (void) {
    double n;

    scanf("%lf", &n);

    // "+" prefixa sinal
    // E -> notação científica (letra maiúscula)
    printf("%+.4E\n", n);

    return 0;
}
