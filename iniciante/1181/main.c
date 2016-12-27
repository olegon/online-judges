/*
Linha na Matriz
https://www.urionlinejudge.com.br/judge/pt/problems/view/1181
*/

#include <stdio.h>

#define LINHAS 12
#define COLUNAS 12

void    preencherMatriz(double matriz[][COLUNAS]);
float   computarOperacao(char operacao, double *valores);

int main (void) {
    int     linhaDaOperacao;
    char    operacao;
    double  matriz[LINHAS][COLUNAS];

    scanf("%d\n", &linhaDaOperacao);
    scanf("%c", &operacao);

    preencherMatriz(matriz);

    printf("%.1f\n", computarOperacao(operacao, matriz[linhaDaOperacao]));

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

float computarOperacao(char operacao, double *valores) {
    double  soma = 0;
    size_t  j;

    for (j = 0; j < COLUNAS; j++) {
        soma += valores[j];
    }

    if (operacao == 'S') {
        return soma;
    }
    else {
        return soma / COLUNAS;
    }
}
