/*
Sequência de Sequência
https://www.urionlinejudge.com.br/judge/pt/problems/view/2028
*/

#include <stdio.h>

int tamanhoDaSequencia(int numero);
void imprimirSequencia(int numero);

int main (void) {
    int numero,
        i,
        caso = 1,
        tamanhoTotalDaSequencia;

    while (scanf("%d\n", &numero) != EOF) {
        tamanhoTotalDaSequencia = 0;
        for (i = 0; i <= numero; i++) {
            tamanhoTotalDaSequencia += tamanhoDaSequencia(i);
        }

        printf("Caso %d: %d %s\n", caso++, tamanhoTotalDaSequencia, tamanhoTotalDaSequencia == 1 ? "numero" : "numeros");

        for (i = 0; i <= numero; i++) {
            imprimirSequencia(i);

            if (i < numero) {
                printf(" ");
            }
            else {
                printf("\n");
            }
        }

        printf("\n");
    }

    return 0;
}

int tamanhoDaSequencia(int numero) {
    if (numero < 2) {
        return 1;
    }
    else {
        return numero;
    }
}

void imprimirSequencia(int numero) {
    int i,
        n = tamanhoDaSequencia(numero);

    for (i = 0; i < n; i++) {
        printf("%d", numero);

        if (i < n - 1) {
            printf(" ");
        }
    }
}
