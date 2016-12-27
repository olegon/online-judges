/*
Número Perfeito
https://www.urionlinejudge.com.br/judge/pt/problems/view/1164
*/

#include <stdio.h>

int main (void) {
    int casos,
        n,
        i,
        soma;

    scanf("%d", &casos);

    while (casos-- > 0) {
        scanf("%d", &n);

        soma = 0;

        for (i = 1; i < n; i++) {
            if (n % i == 0) {
                soma += i;
            }
        }

        if (n == soma) {
            printf("%d eh perfeito\n", n);
        }
        else {
            printf("%d nao eh perfeito\n", n);
        }
    }

    return 0;
}
