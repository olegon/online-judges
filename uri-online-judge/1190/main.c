/*
Área Direita
https://www.urionlinejudge.com.br/judge/pt/problems/view/1190
*/

#include <stdio.h>

#define LINHAS 12
#define COLUNAS 12

void    preencherMatriz(double matriz[][COLUNAS]);
double  computarOperacao(char operacao, double matriz[][COLUNAS]);

int main (void) {
    char    operacao;
    double  matriz[LINHAS][COLUNAS];

    scanf("%c", &operacao);

    preencherMatriz(matriz);

    printf("%.1f\n", computarOperacao(operacao, matriz));

    return 0;
}

void preencherMatriz(double matriz[][COLUNAS]) {
    size_t  i,
            j;

    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
}

double computarOperacao(char operacao, double matriz[][COLUNAS]) {
    double  soma = 0;
    size_t  i,
            j,
            posicoesSomadas = 0;

    for (i = 0; i < LINHAS / 2; i++) {
        for (j = 0; j < i; j++) {
            // printf("[%d, %d] ", i, COLUNAS - j - 1);
            soma += matriz[i][COLUNAS - j - 1];
            posicoesSomadas++;
        }
        // printf("\n");
    }

    for (i = LINHAS / 2; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS - i - 1; j++) {
            // printf("[%d, %d] ", i, COLUNAS - j - 1);
            soma += matriz[i][COLUNAS - j - 1];
            posicoesSomadas++;
        }
        // printf("\n");
    }

    if (operacao == 'S') {
        return soma;
    }
    else {
        return soma / posicoesSomadas;
    }
}
