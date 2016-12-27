/*
Maior e Posição
https://www.urionlinejudge.com.br/judge/pt/problems/view/1080
*/

#include <stdio.h>

int main (void) {
    int i,
        n,
        maiorNumero,
        indiceDoMaiorNumero;

    for (i = 1; i < 101; i++) {
        scanf("%d", &n);

        if (i == 1) {
            maiorNumero = n;
            indiceDoMaiorNumero = i;
        }
        else if (n > maiorNumero) {
            maiorNumero = n;
            indiceDoMaiorNumero = i;
        }
    }

    printf("%d\n%d\n", maiorNumero, indiceDoMaiorNumero);

    return 0;
}
