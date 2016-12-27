/*
Menor e Posição
https://www.urionlinejudge.com.br/judge/pt/problems/view/1180
*/

#include <stdio.h>

#define SIZE 1000

int main (void) {
    int vetor[SIZE],
        i,
        tamanhoDoVetor;

    int indiceDoMenorValor = 0,
        menorValor;

    scanf("%d", &tamanhoDoVetor);

    scanf("%d", &menorValor);

    for (i = 1; i < tamanhoDoVetor; i++) {
        scanf("%d", &vetor[i]);

        if (vetor[i] < menorValor) {
            menorValor = vetor[i];
            indiceDoMenorValor = i;
        }
    }

    printf("Menor valor: %d\n", menorValor);
    printf("Posicao: %d\n", indiceDoMenorValor);

    return 0;
}
