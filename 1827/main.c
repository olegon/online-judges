/*
Matriz Quadrada IV
https://www.urionlinejudge.com.br/judge/pt/problems/view/1827
*/

#include <stdio.h>

#define LINHAS 128
#define COLUNAS 128

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
    int ij,
        i,
        j;

    // Preenche toda a matriz com 0
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matriz[i][j] = 0;
        }
    }

    for (ij = 0; ij < n; ij++) {
        // Diagonal principal com 2
        matriz[ij][ij] = 2;

        // Diagonal secundária com 3
        matriz[n - ij - 1][ij] = 3;
    }

    // Preenche o centro com 1
    for (i = n / 3; i < n - n / 3; i++) {
        for (j = n / 3; j < n - n / 3; j++) {
            matriz[i][j] = 1;
        }
    }

    // Meio com 4
    matriz[n / 2][n / 2] = 4;
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

    printf("\n");
}
