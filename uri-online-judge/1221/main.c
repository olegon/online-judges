/*
Primo Rápido
https://www.urionlinejudge.com.br/judge/pt/problems/view/1221
*/

#include <stdio.h>
#include <math.h>

int ehPrimo(int numero);

int main (void) {
    int casos,
        numero,
        i;

    scanf("%d", &casos);

    for (i = 0; i < casos; i++) {
        scanf("%d", &numero);

        if (ehPrimo(numero)) {
            printf("Prime\n");
        }
        else {
            printf("Not Prime\n");
        }
    }


    return 0;
}

int ehPrimo(int numero) {
    if (numero < 2) {
        return 0;
    }
    else if (numero == 2) {
        return 1;
    }
    else if (numero % 2 == 0) {
        return 0;
    }
    else {
        int i,
            ate = (int)sqrt(numero) + 1;
        for (i = 3; i < ate; i += 2) {
            if (numero % i == 0) {
                return 0;
            }
        }
    }

    return 1;
}
