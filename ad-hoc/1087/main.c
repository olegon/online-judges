/*
Dama
https://www.urionlinejudge.com.br/judge/pt/problems/view/1087
*/

#include <stdio.h>

#define ABS(n) ((n) < 0 ? -(n) : (n))

int main (void) {
    int x1, y1,
        x2, y2;

    while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2), x1 != 0 || y1 != 0 || x2 != 0 || y2 != 0) {
        // Mesma posição
        if (x1 == x2 && y1 == y2) {
            printf("0\n");
        }

        // Mesma linha / Mesma coluna
        else if (x1 == x2 || y1 == y2) {
            printf("1\n");
        }

        // Diagonal
        else if (ABS(x1 - x2) == ABS(y1 - y2)) {
            printf("1\n");
        }

        // Outro
        else {
            printf("2\n");
        }
    }

    return 0;
}
