/*
Maratona de Programação da SBC - ACM ICPC - 2016
Problema I

~ 3N

*/

#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

#define TAMANHO_MAXIMO 50000

int main (void) {
    int N,
        COLUNAS[TAMANHO_MAXIMO],
        i,
        maiorTriangulo = 1;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", COLUNAS + i);
    }

    COLUNAS[0] = COLUNAS[N - 1] = 1;

    // Verificar pela direita.
    for (i = 1; i < N; i++) {
        if (COLUNAS[i] > COLUNAS[i - 1]) {
            COLUNAS[i] = COLUNAS[i - 1] + 1;
        }
    }

    // Verificar pela esquerda.
    for (i = N - 2; i > 0; i--) {
        if (COLUNAS[i] > COLUNAS[i + 1]) {
            COLUNAS[i] = COLUNAS[i + 1] + 1;
        }
    }

    // Procurar o maior
    for (i = 0; i < N; i++) {
        if (COLUNAS[i] > maiorTriangulo) {
            maiorTriangulo = COLUNAS[i];
        }
    }

    printf("%d\n", maiorTriangulo);

    return 0;
}
