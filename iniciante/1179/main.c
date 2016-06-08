#include <stdio.h>

#define ehPar(n) ((n) % 2 != 0 ? 0 : 1)

#define ARRAY_SIZE 5
#define SIZE 15

void imprimir(const char *nomeDoVetor, int *vetor, size_t size);

int main (void) {
    int i,
        n;

    int pares[ARRAY_SIZE],
        paresLength = 0;

    int impares[ARRAY_SIZE],
        imparesLength = 0;

    for (i = 0; i < SIZE; i++) {
        scanf("%d", &n);

        if (ehPar(n)) {
            pares[paresLength++] = n;
        }
        else {
            impares[imparesLength++] = n;
        }

        if (paresLength == ARRAY_SIZE) {
            imprimir("par", pares, paresLength);
            paresLength = 0;
        } else if (imparesLength == ARRAY_SIZE) {
            imprimir("impar", impares, imparesLength);
            imparesLength = 0;
        }
    }

    if (imparesLength > 0) {
        imprimir("impar", impares, imparesLength);
    }

    if (paresLength > 0) {
        imprimir("par", pares, paresLength);
    }


    return 0;
}

void imprimir(const char *nomeDoVetor, int *vetor, size_t size) {
    size_t i;

    for (i = 0; i < size; i++) {
        printf("%s[%d] = %d\n", nomeDoVetor, i, vetor[i]);
    }
}
