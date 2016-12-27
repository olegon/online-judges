/*
Crescimento Populacional
https://www.urionlinejudge.com.br/judge/pt/problems/view/1160
*/

#include <stdio.h>
#include <math.h>

int main (void) {
    int casos,
        anos;

    int     pa, pb;
    double  ga, gb;

    scanf("%d\n", &casos);

    while (casos-- > 0) {
        scanf("%d %d %lf %lf\n", &pa, &pb, &ga, &gb);

        ga = ga / 100 + 1;
        gb = gb / 100 + 1;

        for (anos = 1; anos <= 100; anos++) {
            pa *= ga;
            pb *= gb;

            if (pa > pb) {
                printf("%d anos.\n", anos);
                break;
            }
        }

        if (anos > 100) {
            printf("Mais de 1 seculo.\n");
        }
    }

    return 0;
}
