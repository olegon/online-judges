/*
Crescente e Decrescente
https://www.urionlinejudge.com.br/judge/pt/problems/view/1113
*/

#include <stdio.h>

int main (void) {
    int x,
        y;

    while (scanf("%d %d\n", &x, &y), x != y) {
        if (x < y) {
            printf("Crescente\n");
        }
        else {
            printf("Decrescente\n");
        }
    }

    return 0;
}
