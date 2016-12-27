/*
Resto da Divisão
https://www.urionlinejudge.com.br/judge/pt/problems/view/1133
*/

#include <stdio.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main (void) {
    int a,
        b,
        min,
        max,
        resto,
        i;

    scanf("%d %d", &a, &b);

    min = MIN(a, b) + 1;
    max = MAX(a, b);

    for (i = min; i < max; i++) {
        resto = i % 5;
        if (resto == 2 || resto == 3) {
            printf("%d\n", i);
        }
    }

    return 0;
}
