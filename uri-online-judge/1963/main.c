/*
O Filme
https://www.urionlinejudge.com.br/judge/pt/problems/view/1963
*/

#include <stdio.h>

int main (void) {
    double  valorAnterior,
            valorAtual;

    scanf("%lf %lf", &valorAnterior, &valorAtual);

    printf("%.2f%%\n", (valorAtual / valorAnterior - 1.0) * 100.0);

    return 0;
}
