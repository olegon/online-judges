#include <stdio.h>

#define TAMANHO_MAXIMO 200
#define VISITADO -1

int buscarTamanhoDaSequencia(int parede[][TAMANHO_MAXIMO], int i, int j, int m, int n, int cor);

int main (void) {
    int parede[TAMANHO_MAXIMO][TAMANHO_MAXIMO],
        m, n,
        i, j,
        tamanhoDaSequencia,
        tamanhoDaMenorSequencia = -1;

    scanf("%d %d", &m, &n);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &parede[i][j]);
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (parede[i][j] != VISITADO) {
                tamanhoDaSequencia = buscarTamanhoDaSequencia(parede, i, j, m, n, parede[i][j]);

                if (tamanhoDaMenorSequencia == -1 || tamanhoDaSequencia < tamanhoDaMenorSequencia) {
                    tamanhoDaMenorSequencia = tamanhoDaSequencia;

                    if (tamanhoDaMenorSequencia == 1) {
                        goto PRINT;
                    }
                }
            }
        }
    }

PRINT:
    printf("%d\n", tamanhoDaMenorSequencia);

    return 0;
}

int buscarTamanhoDaSequencia(int parede[][TAMANHO_MAXIMO], int i, int j, int m, int n, int cor) {
    if (i < 0 || i >= m) {
        return 0;
    }

    if (j < 0 || j >= n) {
        return 0;
    }

    if (parede[i][j] == cor) {
        parede[i][j] = VISITADO;

        return 1
            + buscarTamanhoDaSequencia(parede, i + 1, j, m, n, cor)
            + buscarTamanhoDaSequencia(parede, i - 1, j, m, n, cor)
            + buscarTamanhoDaSequencia(parede, i, j + 1, m, n, cor)
            + buscarTamanhoDaSequencia(parede, i, j - 1, m, n, cor);
    }

    return 0;
}
