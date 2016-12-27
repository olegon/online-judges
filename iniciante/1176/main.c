/*
Fibonacci em Vetor
https://www.urionlinejudge.com.br/judge/pt/problems/view/1176
*/

#include <stdio.h>

#define SIZE 61

void preencherFibonacci(double *vetor, size_t size);

int main (void) {
    double  sequencia[SIZE];

    int casos,
        indice;

    preencherFibonacci(sequencia, SIZE);

    scanf("%d", &casos);

    while (casos-- > 0) {
        scanf("%d", &indice);

        printf("Fib(%d) = %.0f\n", indice, sequencia[indice]);
    }

    return 0;
}

void preencherFibonacci(double *vetor, size_t size) {
    size_t  i;

    vetor[0] = 0.0;
    vetor[1] = 1.0;

    for (i = 2; i < size; i++) {
        vetor[i] = vetor[i - 1] + vetor[i - 2];
    }
}
