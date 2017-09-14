/*
Substituição em Vetor I
https://www.urionlinejudge.com.br/judge/pt/problems/view/1172
*/

#include <stdio.h>

int main (void) {
    int x[10],
        i;

    for (i = 0; i < 10; i++) {
        scanf("%d", &x[i]);

        if (x[i] < 1) {
            x[i] = 1;
        }

        printf("X[%d] = %d\n", i, x[i]);
    }

    return 0;
}
