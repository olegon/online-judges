/*
De Quem é a Vez?
https://www.urionlinejudge.com.br/judge/pt/problems/view/1914
*/

#include <stdio.h>

#define NOME_SIZE   128
#define OPCAO_SIZE  16

int main (void) {
    int     casos;

    char    nomeDoJogador01[NOME_SIZE],
            opcaoDoJogador01[OPCAO_SIZE],
            nomeDoJogador02[NOME_SIZE],
            opcaoDoJogador02[OPCAO_SIZE];

    int     valorJogador01,
            valorJogador02;

    // Premissa: opcaoDoJogador01 != opcaoDoJogador02

    scanf("%d\n", &casos);

    while (casos-- > 0) {
        scanf("%s %s %s %s\n%d %d\n", nomeDoJogador01, opcaoDoJogador01, nomeDoJogador02, opcaoDoJogador02, &valorJogador01, &valorJogador02);

        if ((valorJogador01 + valorJogador02) % 2 != 0) {
            if (opcaoDoJogador01[0] == 'I') {
                printf("%s\n", nomeDoJogador01);
            }
            else {
                printf("%s\n", nomeDoJogador02);
            }
        }
        else {
            if (opcaoDoJogador01[0] == 'P') {
                printf("%s\n", nomeDoJogador01);
            }
            else {
                printf("%s\n", nomeDoJogador02);
            }
        }
    }

    return 0;
}
