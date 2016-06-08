#include <stdio.h>

#define LINHAS 128
#define COLUNAS 128

void montarMatriz(int matriz[][COLUNAS], int n);
void imprimirMatriz(int matriz[][COLUNAS], int n);

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
        matriz[ij][ij] = 1;

        // Abaixo da diagonal principal
        for (i = ij + 1; i < n; i++) {
            matriz[i][ij] = matriz[i - 1][ij] + 1;
        }

        // Acima da diagonal principal
        for (i = ij - 1; i > -1; i--) {
            matriz[i][ij] = matriz[i + 1][ij] + 1;
        }
    }
}

void imprimirMatriz(int matriz[][COLUNAS], int n) {
    int i,
        j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matriz[i][j] >= 100) {
                printf("%d", matriz[i][j]);
            }
            else {
                printf("% 3d", matriz[i][j]);
            }

            if (j < n - 1) {
                printf(" ");
            }
        }

        printf("\n");
    }

    printf("\n");
}
