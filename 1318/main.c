/*
Bilhetes Falsos
https://www.urionlinejudge.com.br/judge/pt/problems/view/1318
*/

#include <stdio.h>
#include <stdlib.h>

#define NUMERO_MAXIMO_DE_BILHETES 20000

int diff(const void *a, const void *b);

int main (void) {
    int N, M,
        BILHETES[NUMERO_MAXIMO_DE_BILHETES];

    while (scanf("%d %d", &N, &M), N != 0 && M != 0) {
        int i;
        int quantidadeDeBilhetesRepetidos = 0;

        for (i = 0; i < M; i++) {
            scanf("%d", BILHETES + i);
        }

        qsort(BILHETES, M, sizeof(int), diff);

        i = 0;
        while (i < M) {
            int bilhete = BILHETES[i++];
            int repetiu = 0;

            while (bilhete == BILHETES[i]) {
                repetiu = 1;
                i++;
            }

            if (repetiu) {
                quantidadeDeBilhetesRepetidos++;
            }
        }

        printf("%d\n", quantidadeDeBilhetesRepetidos);
    }

    return 0;
}

int diff(const void *a, const void *b) {
    const int *ia = a;
    const int *ib = b;

    return *ia - *ib;
}
