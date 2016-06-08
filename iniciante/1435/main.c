#include <stdio.h>

#define LINHAS 100
#define COLUNAS 100

#define ehPar(n) ((n) % 2 != 0 ? 0 : 1)

void montarMatriz(int matriz[][COLUNAS], int n);
void montarBorda(int matriz[][COLUNAS], int n, int ij, int valor);
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
    int i;

    for (i = 0; i < n; i++) {
        montarBorda(matriz, n, i, i + 1);
    }
}

void montarBorda(int matriz[][COLUNAS], int n, int ij, int valor) {
    int i,
        j;

    i = ij;
    for (j = ij; j < n - ij; j++) {
        // superior
        matriz[i][j] = valor;
        // esquerda
        matriz[j][i] = valor;
    }

    i = n - ij - 1;
    for (j = ij; j < n - ij; j++) {
        // inferior
        matriz[i][j] = valor;
        // direita
        matriz[j][i] = valor;
    }
}

void imprimirMatriz(int matriz[][COLUNAS], int n) {
    int i,
        j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("% 3d", matriz[i][j]);
            if (j < n - 1) {
                printf(" ");
            }
        }

        printf("\n");
    }

    printf("\n");
}
