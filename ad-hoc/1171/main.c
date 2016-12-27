/*
Frequência de Números
https://www.urionlinejudge.com.br/judge/pt/problems/view/1171
*/

#include <stdio.h>

#define SIZE 2001

// GCC preenche com 0
int numeros[SIZE];

int main (void) {
    int casos,
        i;

    scanf("%d\n", &casos);

    while (casos-- > 0) {
        scanf("%d", &i);
        numeros[i]++;
    }

    for (i = 1; i < SIZE; i++) {
        if (numeros[i] > 0) {
            printf("%d aparece %d vez(es)\n", i, numeros[i]);
        }
    }

    return 0;
}
