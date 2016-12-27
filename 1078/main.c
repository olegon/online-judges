/*
Tabuada
https://www.urionlinejudge.com.br/judge/pt/problems/view/1078
*/

#include <stdio.h>

int main (void) {
    int n,
        i;

    scanf("%d", &n);

    for (i = 1; i < 11; i++) {
        printf("%d x %d = %d\n", i, n, i * n);
    }

    return 0;
}
