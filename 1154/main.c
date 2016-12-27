/*
Idades
https://www.urionlinejudge.com.br/judge/pt/problems/view/1154
*/

#include <stdio.h>

int main (void) {
    int idade,
        quantidade = 0,
        soma = 0;

    while (scanf("%d", &idade), idade > -1) {
        soma += idade;
        quantidade++;
    }

    printf("%.2f\n", (double)soma / quantidade);

    return 0;
}
