#include <stdio.h>

#define LINHAS 96
#define COLUNAS 96

void montarMatriz(int matriz[][COLUNAS], int n);
void imprimirMatriz(int matriz[][COLUNAS], int n);

int main (void) {
    int n,
        matriz[LINHAS][COLUNAS];

    while(scanf("%d\n", &n) != EOF) {
        montarMatriz(matriz, n);
        imprimirMatriz(matriz, n);
    }

    return 0;
}

void montarMatriz(int matriz[][COLUNAS], int n) {
    int i,
        j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matriz[i][j] = 3;
        }
    }

    for (i = 0; i < n; i++) {
        matriz[i][i] = 1;
        matriz[n - i - 1][i] = 2;
    }
}

void imprimirMatriz(int matriz[][COLUNAS], int n) {
    int i,
        j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d", matriz[i][j]);
        }

        printf("\n");
    }
}
