/*
Guarda Costeira
https://www.urionlinejudge.com.br/judge/pt/problems/view/1247
*/

#include <stdio.h>
#include <math.h>

int main (void) {
    int D, VF, VG;

    while (scanf("%d %d %d\n", &D, &VF, &VG) != EOF) {
        double tF = 12.0 / VF;
        double tG = sqrt(pow(D, 2) + pow(12, 2)) / VG;

        if (tG <= tF) {
            printf("S\n");
        }
        else {
            printf("N\n");
        }
    }

    return 0;
}
