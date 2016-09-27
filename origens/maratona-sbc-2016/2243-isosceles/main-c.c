/*
Maratona de Programação da SBC - ACM ICPC - 2016
Problema I

~ 3N

*/

#include <stdio.h>

#define TAMANHO_MAXIMO 50000

int main (void) {
    int N,
        COLUNAS[TAMANHO_MAXIMO],
        i,
        pelaDireita,
        pelaEsquerda,
        hN,
        maiorTriangulo = 1;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", COLUNAS + i);
    }

    hN = N / 2;

    COLUNAS[0] = COLUNAS[N - 1] = 1;

    for (i = 1; i < N; i++) {
        pelaDireita = i;
        pelaEsquerda = N - 1 - i;

        if (COLUNAS[pelaDireita] > COLUNAS[pelaDireita - 1]) {
            COLUNAS[pelaDireita] = COLUNAS[pelaDireita - 1] + 1;
        }

        if (COLUNAS[pelaEsquerda] > COLUNAS[pelaEsquerda + 1]) {
            COLUNAS[pelaEsquerda] = COLUNAS[pelaEsquerda + 1] + 1;
        }

        if (i >= hN) {
            if (COLUNAS[pelaDireita] > maiorTriangulo) {
                maiorTriangulo = COLUNAS[pelaDireita];
            }

            if (COLUNAS[pelaEsquerda] > maiorTriangulo) {
                maiorTriangulo = COLUNAS[pelaEsquerda];
            }
        }
    }

    printf("%d\n", maiorTriangulo);

    return 0;
}
