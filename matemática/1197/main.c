/*
Volta à Faculdade de Física
https://www.urionlinejudge.com.br/judge/pt/problems/view/1197
*/

#include <stdio.h>

int main (void) {
    int v, t;

    while (scanf("%d %d", &v, &t) != EOF) {
        printf("%d\n", v * t * 2);
    }

    return 0;
}
