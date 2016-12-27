/*
Tempo de Jogo
https://www.urionlinejudge.com.br/judge/pt/problems/view/1046
*/

#include <stdio.h>

int main (void) {
    int comeco, fim, duracao;

    scanf("%d %d", &comeco, &fim);

    if (comeco < fim) {
        duracao = fim - comeco;
    }
    else {
        duracao = 24 - comeco + fim;
    }

    printf("O JOGO DUROU %d HORA(S)\n", duracao);

    return 0;
}
