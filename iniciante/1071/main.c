/*
Soma de Impares Consecutivos I
https://www.urionlinejudge.com.br/judge/pt/problems/view/1071
*/

#include <stdio.h>

int main (void) {
    int inicio,
        fim,
        inc,
        i,
        soma = 0;

    scanf("%d %d", &inicio, &fim);

    if (inicio == fim) {
        printf("0\n");
    }
    else {
        inc = fim > inicio ? 1 : -1;

        for (i = inicio + inc; i != fim; i += inc) {
            if (i % 2 != 0) {
                soma += i;
            }
        }

        printf("%d\n", soma);
    }


    return 0;
}
