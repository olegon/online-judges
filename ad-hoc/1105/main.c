/*
Sub-prime
https://www.urionlinejudge.com.br/judge/pt/problems/view/1105
*/

#include <stdio.h>

#define MAXIMO_DE_BANCOS 20
int main (void) {
    int B, N,
        D, C, V;

    int bancos[MAXIMO_DE_BANCOS];

    while (scanf("%d %d", &B, &N), B != 0 || N != 0) {
        int i,
            crise = 0;

        for (i = 0; i < B; i++) {
            scanf("%d", bancos + i);
        }

        for (i = 0; i < N; i++) {
            scanf("%d %d %d", &D, &C, &V);

            bancos[D - 1] -= V;
            bancos[C - 1] += V;
        }

        for (i = 0; i < B; i++) {
            if (bancos[i] < 0) {
                crise = 1;
                break;
            }
        }

        if (crise) {
            printf("N\n");
        }
        else {
            printf("S\n");
        }
    }

    return 0;
}
