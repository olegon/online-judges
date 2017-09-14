/*
Bazinga!
https://www.urionlinejudge.com.br/judge/pt/problems/view/1828
*/

#include <stdio.h>
#include <string.h>

typedef enum {
    TESOURA,
    PAPEL,
    PEDRA,
    LAGARTO,
    SPOCK,
    DESCONHECIDO
} VALOR;

int jogar (const char *escolhaDoJogador01, const char *escolhaDoJogador02);
VALOR obterValorCorrespondente (const char *escolha);

#define STRING_SIZE 32

int main (void) {
    int     casos,
            i,
            vencedor;

    char    escolhaDoJogador01[STRING_SIZE],
            escolhaDoJogador02[STRING_SIZE];


    scanf("%d\n", &casos);

    for (i = 1; i <= casos; i++) {
        scanf("%s %s\n", escolhaDoJogador01, escolhaDoJogador02);

        vencedor = jogar(escolhaDoJogador01, escolhaDoJogador02);

        if (vencedor == 0) {
            printf("Caso #%d: De novo!\n", i);
        }
        else if (vencedor == 1) {
            printf("Caso #%d: Bazinga!\n", i);
        }
        else {
            printf("Caso #%d: Raj trapaceou!\n", i);
        }
    }

    return 0;
}

int jogar (const char *escolhaDoJogador01, const char *escolhaDoJogador02) {
    VALOR   valorJogador1,
            valorJogador2;

    valorJogador1 = obterValorCorrespondente(escolhaDoJogador01);
    valorJogador2 = obterValorCorrespondente(escolhaDoJogador02);

    if (valorJogador1 == valorJogador2) {
        return 0;
    }
    else if (valorJogador1 == TESOURA && valorJogador2 == PAPEL) {
        return 1;
    }
    else if (valorJogador1 == PAPEL && valorJogador2 == PEDRA) {
        return 1;
    }
    else if (valorJogador1 == PEDRA && valorJogador2 == LAGARTO) {
        return 1;
    }
    else if (valorJogador1 == LAGARTO && valorJogador2 == SPOCK) {
        return 1;
    }
    else if (valorJogador1 == SPOCK && valorJogador2 == TESOURA) {
        return 1;
    }
    else if (valorJogador1 == TESOURA && valorJogador2 == LAGARTO) {
        return 1;
    }
    else if (valorJogador1 == LAGARTO && valorJogador2 == PAPEL) {
        return 1;
    }
    else if (valorJogador1 == PAPEL && valorJogador2 == SPOCK) {
        return 1;
    }
    else if (valorJogador1 == SPOCK && valorJogador2 == PEDRA) {
        return 1;
    }
    else if (valorJogador1 == PEDRA && valorJogador2 == TESOURA) {
        return 1;
    }
    else {
        return 2;
    }

    return 0;
}

VALOR obterValorCorrespondente (const char *escolha) {
    if (strcmp(escolha, "tesoura") == 0) {
        return TESOURA;
    }

    if (strcmp(escolha, "papel") == 0) {
        return PAPEL;
    }

    if (strcmp(escolha, "pedra") == 0) {
        return PEDRA;
    }

    if (strcmp(escolha, "lagarto") == 0) {
        return LAGARTO;
    }

    if (strcmp(escolha, "Spock") == 0) {
        return SPOCK;
    }

    return DESCONHECIDO;
}
