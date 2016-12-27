/*
Múltiplos de 13
https://www.urionlinejudge.com.br/judge/pt/problems/view/1132
*/

#include <stdio.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main (void) {
    int a,
        b,
        min,
        max,
        i,
        soma = 0;

    scanf("%d %d", &a, &b);

    min = MIN(a, b);
    max = MAX(a, b) + 1;

    for (i = min; i < max; i++) {
        if (i % 13 != 0) {
            soma += i;
        }
    }

    printf("%d\n", soma);

    return 0;
}
