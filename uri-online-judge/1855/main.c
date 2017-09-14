/*
Mapa do Meistre
https://www.urionlinejudge.com.br/judge/pt/problems/view/1855
*/

#include <stdio.h>

#define LINHAS  128
#define COLUNAS 128

#define LESTE   '>'
#define OESTE   '<'
#define NORTE   '^'
#define SUL     'v'

#define BAU         '*'
#define VISITADO    '@'

void preencherMapa(char mapa[][COLUNAS], int linhas, int colunas);
void exibirMapa(char mapa[][COLUNAS], int linhas, int colunas);
int encontrouBau(char mapa[][COLUNAS], int linhas, int colunas, int i, int j, char direcao);

int main (void) {
    char    mapa[LINHAS][COLUNAS];
    int     linhas, colunas;

    scanf("%d %d\n", &colunas, &linhas);

    preencherMapa(mapa, linhas, colunas);

    if (encontrouBau(mapa, linhas, colunas, 0, 0, mapa[0][0])) {
        printf("*\n");
    }
    else {
        printf("!\n");
    }

    return 0;
}

void preencherMapa(char mapa[][COLUNAS], int linhas, int colunas) {
    int i,
        j;

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            scanf("%c", &mapa[i][j]);
        }

        scanf("\n");
    }
}

void exibirMapa(char mapa[][COLUNAS], int linhas, int colunas) {
    int i,
        j;

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%c", mapa[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

int encontrouBau(char mapa[][COLUNAS], int linhas, int colunas, int i, int j, char direcao) {
    // Verificar se saiu do mapa;
    if (i < 0 || i >= linhas)   return 0;
    if (j < 0 || j >= colunas)  return 0;


    // Verificar se encontrou o baú ou se já passou pelo lugar
    switch (mapa[i][j]) {
        case BAU:
            return 1;
        case VISITADO:
            return 0;
    }


    // Verificar se deve trocar de direção
    if (mapa[i][j] == LESTE) {
        mapa[i][j] = VISITADO;
        return encontrouBau(mapa, linhas, colunas, i, j + 1, LESTE);
    }

    if (mapa[i][j] == OESTE) {
        mapa[i][j] = VISITADO;
        return encontrouBau(mapa, linhas, colunas, i, j - 1, OESTE);
    }

    if (mapa[i][j] == NORTE) {
        mapa[i][j] = VISITADO;
        return encontrouBau(mapa, linhas, colunas, i - 1, j, NORTE);
    }

    if (mapa[i][j] == SUL) {
        mapa[i][j] = VISITADO;
        return encontrouBau(mapa, linhas, colunas, i + 1, j, SUL);
    }


    // Continuar na direção
    if (direcao == LESTE) {
        mapa[i][j] = VISITADO;
        return encontrouBau(mapa, linhas, colunas, i, j + 1, LESTE);
    }

    if (direcao == OESTE) {
        mapa[i][j] = VISITADO;
        return encontrouBau(mapa, linhas, colunas, i, j - 1, OESTE);
    }

    if (direcao == NORTE) {
        mapa[i][j] = VISITADO;
        return encontrouBau(mapa, linhas, colunas, i - 1, j, NORTE);
    }

    if (direcao == SUL) {
        mapa[i][j] = VISITADO;
        return encontrouBau(mapa, linhas, colunas, i + 1, j, SUL);
    }


    // Input inválido
    return 0;
}
