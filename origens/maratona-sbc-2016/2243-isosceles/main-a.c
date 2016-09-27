/*
Maratona de Programação da SBC - ACM ICPC - 2016
Problema I

Big Oh(N²)

*/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAXIMO 50000

#define DIREITA 1
#define ESQUERDA -1

int formaTriangulo(const int *COLUNAS, int indice, int tamanho);
int verificarAltura(const int *COLUNAS, int indice, int tamanho, int direcao);

int main (void) {
    int N,
        COLUNAS[TAMANHO_MAXIMO],
        i,
        j,
        maiorColuna,
        maiorColunaDoLaco;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", COLUNAS + i);
    }

    // Maior coluna encontrada = 1
    maiorColuna = 1;
    maiorColunaDoLaco = 1;

    // Testar para tamnho i -> [2, ..., N]
    for (i = 2; i <= N; i++) {
        // Testar entre as colunas j -> [i - 1, ..., N - i]
        for (j = i - 1; j <= N - i; j++) {
            // Se encontrou um triângulo, gravar a maior altura registrada e testar uma altura maior
            if (formaTriangulo(COLUNAS, j, i)) {
                maiorColunaDoLaco = i;
                break;
            }
        }

        // Se o triângulo não for maior que o anterior, então chegamos na maior triângulo possível
        if (maiorColuna == maiorColunaDoLaco) {
            break;
        }

        maiorColuna = maiorColunaDoLaco;
    }

    printf("%d\n", maiorColuna);

    return 0;
}

int formaTriangulo(const int *COLUNAS, int indice, int tamanho) {
    if (COLUNAS[indice] >= tamanho) {
        return verificarAltura(COLUNAS, indice - 1, tamanho - 1, ESQUERDA) && verificarAltura(COLUNAS, indice + 1, tamanho - 1, DIREITA);
    }
    else {
        return 0;
    }
}

int verificarAltura(const int *COLUNAS, int indice, int tamanho, int direcao) {
    if (tamanho == 1) {
        return 1;
    }
    else if (COLUNAS[indice] >= tamanho){
        return verificarAltura(COLUNAS, indice + direcao, tamanho - 1, direcao);
    }
    else {
        return 0;
    }
}
