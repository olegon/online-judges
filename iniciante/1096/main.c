/*
Sequencia IJ 2
https://www.urionlinejudge.com.br/judge/pt/problems/view/1096
*/

#include <stdio.h>

int main (void) {
    int i,
        j;

    for (i = 1; i < 10; i += 2) {
        for (j = 7; j > 4; j--) {
            printf("I=%d J=%d\n", i, j);
        }
    }


    return 0;
}
