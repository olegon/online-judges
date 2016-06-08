#include <stdio.h>

#define LINHAS 12
#define COLUNAS 12

void    preencherMatriz(double matriz[][COLUNAS]);
double  computarOperacao(char operacao, int coluna, double matriz[][COLUNAS]);

int main (void) {
    int     colunaDaOperacao;
    char    operacao;
    double  matriz[LINHAS][COLUNAS];

    scanf("%d\n", &colunaDaOperacao);
    scanf("%c", &operacao);

    preencherMatriz(matriz);

    printf("%.1f\n", computarOperacao(operacao, colunaDaOperacao, matriz));

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

double computarOperacao(char operacao, int coluna, double matriz[][COLUNAS]) {
    double  soma = 0;
    size_t  i;

    for (i = 0; i < COLUNAS; i++) {
        soma += matriz[i][coluna];
    }

    if (operacao == 'S') {
        return soma;
    }
    else {
        return soma / COLUNAS;
    }
}
