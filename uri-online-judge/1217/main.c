/*
Getline Two - Frutas
https://www.urionlinejudge.com.br/judge/pt/problems/view/1217
*/

#include <stdio.h>

#define STRING_SIZE 1024

int main (void) {
    int quantidadeDeDias,
        i,
        quantidadeDeFrutasPorDia;

    double  gastoPorDia,
            gastoTotal = 0.0,
            quantidadeDeFrutasTotal = 0.0;

    char    nomeDaFruta[STRING_SIZE],
            caractereAposNomeDaFruta;

    scanf("%d\n", &quantidadeDeDias);

    for (i = 1; i <= quantidadeDeDias; i++) {
        scanf("%lf\n", &gastoPorDia);
        gastoTotal += gastoPorDia;

        quantidadeDeFrutasPorDia = 0;
        while (1) {
            scanf("%s%c", nomeDaFruta, &caractereAposNomeDaFruta);

            quantidadeDeFrutasPorDia++;
            if (caractereAposNomeDaFruta == '\n') {
                break;
            }
        }
        quantidadeDeFrutasTotal += quantidadeDeFrutasPorDia;

        printf("day %d: %d kg\n", i, quantidadeDeFrutasPorDia);
    }

    printf("%.2f kg by day\n", quantidadeDeFrutasTotal / quantidadeDeDias);
    printf("R$ %.2f by day\n", gastoTotal / quantidadeDeDias);

    return 0;
}
