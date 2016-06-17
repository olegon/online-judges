#include <stdio.h>

int main (void) {
    double  distancia,
            distanciaTotal = 0;

    int caractere,
        quantidade = 0;

    while (caractere = getc(stdin), caractere != EOF) {
        while (caractere != '\n') {
            caractere = getc(stdin);
        }

        scanf("%lf\n", &distancia);

        distanciaTotal += distancia;
        quantidade++;
    }

    printf("%.1f\n", distanciaTotal / quantidade);

    return 0;
}
