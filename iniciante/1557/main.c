#include <stdio.h>

#define LINHAS 128
#define COLUNAS 128

void montarMatriz(int matriz[][COLUNAS], int n);
void imprimirMatriz(int matriz[][COLUNAS], int n);
int quantidadeDeAlgarismos(int n);

int main (void) {
    int n,
        matriz[LINHAS][COLUNAS];

    while(scanf("%d", &n), n != 0) {
        montarMatriz(matriz, n);
        imprimirMatriz(matriz, n);
    }

    return 0;
}

void montarMatriz(int matriz[][COLUNAS], int n) {
    int ij,
        i;

    for (ij = 0; ij < n; ij++) {
        if (ij == 0) {
            matriz[ij][ij] = 1;
        }
        else {
            matriz[ij][ij] = matriz[ij - 1][ij - 1] * 4;
        }

        // Abaixo da diagonal principal
        for (i = ij + 1; i < n; i++) {
            matriz[i][ij] = matriz[i - 1][ij] * 2;
        }

        // Acima da diagonal principal
        for (i = ij - 1; i > -1; i--) {
            matriz[i][ij] = matriz[i + 1][ij] / 2;
        }
    }
}

void imprimirMatriz(int matriz[][COLUNAS], int n) {
    int i,
        j,
        maiorNumero;

    char format[64];

    maiorNumero = matriz[n - 1][n - 1];
    sprintf(format, "%%%dd", quantidadeDeAlgarismos(maiorNumero));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf(format, matriz[i][j]);

            if (j < n - 1) {
                printf(" ");
            }
        }

        printf("\n");
    }

    printf("\n");
}

int quantidadeDeAlgarismos(int n) {
    if (n < 10) {
        return 1;
    }
    else {
        return 1 + quantidadeDeAlgarismos(n / 10);
    }
}
