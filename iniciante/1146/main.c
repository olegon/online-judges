/*
Sequências Crescentes
https://www.urionlinejudge.com.br/judge/pt/problems/view/1146
*/

#include <stdio.h>

int main (void) {
    int i,
        n;

    while(scanf("%d", &n), n) {
        for (i = 1; i <= n; i++) {
            printf("%d%c", i, i == n ? '\n' : ' ');
        }
    }

    return 0;
}
