/*
Há Muito, Muito Tempo Atrás
https://www.urionlinejudge.com.br/judge/pt/problems/view/1962
*/

#include <stdio.h>

#define ANO_ATUAL 2015

void imprimirAno(int ano);

int main (void) {
    int casos,
        ano;

    scanf("%d", &casos);

    while (casos-- > 0) {
        scanf("%d", &ano);
        imprimirAno(ano);
    }

    return 0;
}

void imprimirAno(int ano) {
    int diferenca;

    diferenca = ANO_ATUAL - ano;

    if (diferenca <= 0) {
        printf("%d A.C.\n", -diferenca + 1);
    }
    else {
        printf("%d D.C.\n", diferenca);
    }
}
