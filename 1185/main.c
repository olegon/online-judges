/*
Acima da Diagonal Secundária
https://www.urionlinejudge.com.br/judge/pt/problems/view/1185
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

    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS - i - 1; j++) {
            soma += matriz[i][j];
            posicoesSomadas++;
        }
    }

    if (operacao == 'S') {
        return soma;
    }
    else {
        return soma / posicoesSomadas;
    }
}
