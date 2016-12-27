/*
Sequencia IJ 4
https://www.urionlinejudge.com.br/judge/pt/problems/view/1098
*/

#include <stdio.h>
#include <math.h>

int main (void) {
    float   i,
            j;

    for (i = 0.0; i < 2.2; i += 0.2) {
        for (j = 1.0; j < 4.0; j++) {
            if (i == 0.0 || i == 1.0 || i > 1.9) {
                printf("I=%.0f J=%.0f\n", i, j + i);
            }
            else {
                printf("I=%.1f J=%.1f\n", i, j + i);
            }
        }
    }


    return 0;
}
