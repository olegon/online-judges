/*
Trigo no Tabuleiro
https://www.urionlinejudge.com.br/judge/pt/problems/view/1169
*/

#include <stdio.h>
#include <math.h>

int main (void) {
    int casos,
        n;
    scanf("%d", &casos);

    while (casos-- > 0) {
        scanf("%d", &n);

        printf("%.0f kg\n", floor(pow(2, n) / 12000));
    }

    return 0;
}
