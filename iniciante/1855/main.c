#include <stdio.h>

// TODO: terminar o problema :]

#define LINHAS  128
#define COLUNAS 128

#define LESTE   '>'
#define OESTE   '<'
#define NORTE   '^'
#define SUL     'v'

#define BAU         '*'
#define VISITADO    '@'

void preencherMapa(char mapa[][COLUNAS], int linhas, int colunas);
int encontrouBau(char mapa[][COLUNAS], int linhas, int colunas, int i, int j, char direcao);

int main (void) {
    char    mapa[LINHAS][COLUNAS];
    int     linhas, colunas;

    scanf("%d %d\n", &colunas, &linhas);

    preencherMapa(mapa, linhas, colunas);
    encontrouBau(mapa, linhas, colunas, 0, 0, mapa[0][0]);

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

int encontrouBau(char mapa[][COLUNAS], int linhas, int colunas, int i, int j, char direcao) {
    if (i < 0 || i >= linhas)   return 0;
    if (j < 0 || j >= colunas)  return 0;


    switch (mapa[i][j]) {
        case BAU:
            return 1;
        case VISITADO:
            return 0;
    }

    mapa[i][j] = VISITADO;

    switch (mapa[i][j]) {
        case LESTE:
            return encontrouBau(mapa, linhas, colunas, i, j + 1, LESTE);
        case OESTE:
            return encontrouBau(mapa, linhas, colunas, i, j - 1, NORTE);
        case NORTE:
            return encontrouBau(mapa, linhas, colunas, i - 1, j, NORTE);
        case SUL:
            return encontrouBau(mapa, linhas, colunas, i + 1, j, SUL);
    }

    switch (direcao) {
        case LESTE:
            return encontrouBau(mapa, linhas, colunas, i, j + 1, LESTE);
        case OESTE:
            return encontrouBau(mapa, linhas, colunas, i, j - 1, NORTE);
        case NORTE:
            return encontrouBau(mapa, linhas, colunas, i - 1, j, NORTE);
        case SUL:
            return encontrouBau(mapa, linhas, colunas, i + 1, j, SUL);
    }

    return 0;
}
