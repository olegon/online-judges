/*
Dividindo X por Y
https://www.urionlinejudge.com.br/judge/pt/problems/view/1116
*/

#include <stdio.h>

int main (void) {
    int n,
        x,
        y;

    scanf("%d\n", &n);

    while (n-- > 0) {
        scanf("%d %d\n", &x, &y);

        if (y == 0) {
            printf("divisao impossivel\n");
        }
        else {
            printf("%.1f\n", (double)x / y);
        }
    }

    return 0;
}
