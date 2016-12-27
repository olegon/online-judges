/*
Mensagem Oculta
https://www.urionlinejudge.com.br/judge/pt/problems/view/1272
*/

#include <stdio.h>

#define ESPACO(c) ((c) == ' ')

void imprimirMensagemOculpa(const char *linha);

#define TAMANHO_DA_LINHA 64

int main (void) {
    int     casos;
    char    linha[TAMANHO_DA_LINHA];

    scanf("%d\n", &casos);

    while (casos-- > 0) {
        fgets(linha, TAMANHO_DA_LINHA, stdin);
        // printf("%s", linha);
        imprimirMensagemOculpa(linha);
    }

    return 0;
}

void imprimirMensagemOculpa(const char *linha) {
    int lendoPalavra = 0;

    while (*linha != '\n') {
        if (ESPACO(*linha)) {
            lendoPalavra = 0;
        }
        else if (!lendoPalavra) {
            putc(*linha, stdout);
            lendoPalavra = 1;
        }

        linha++;
    }

    putc('\n', stdout);
}
