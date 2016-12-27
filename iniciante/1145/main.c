/*
Sequência Lógica 2
https://www.urionlinejudge.com.br/judge/pt/problems/view/1145
*/

#include <stdio.h>

int main (void) {
    int x,
        y,
        i;

    scanf("%d %d", &x, &y);

    for (i = 1; i <= y; i++) {
        printf("%d%c", i, i % x == 0 ? '\n' : ' ');
    }

    return 0;
}
