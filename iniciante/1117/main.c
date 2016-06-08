#include <stdio.h>

int main (void) {
    double  nota,
            soma = 0.0;

    int quantidadeDeNotasValidas = 0;

    while (quantidadeDeNotasValidas < 2) {
        scanf("%lf\n", &nota);

        if (nota < 0 || nota > 10) {
            printf("nota invalida\n");
        }
        else {
            soma += nota;
            quantidadeDeNotasValidas++;
        }
    }

    printf("media = %.2f\n", soma / 2);

    return 0;
}
