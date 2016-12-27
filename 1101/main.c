/*
Sequência de Números e Soma
https://www.urionlinejudge.com.br/judge/pt/problems/view/1101
*/

#include <stdio.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main (void) {
    int m,
        n;

    int min,
        max,
        soma;

    while (scanf("%d %d\n", &m, &n), m > 0 && n > 0) {
        min = MIN(m, n);
        max = MAX(m, n) + 1;

        soma = 0;
        while (min < max) {
            printf("%d ", min);
            soma += min++;
        }
        printf("Sum=%d\n", soma);
    }


    return 0;
}
