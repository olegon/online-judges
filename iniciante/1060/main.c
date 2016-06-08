#include <stdio.h>

int main (void) {
    int i, q = 0;
    double numero;


    for (i = 0; i < 6; i++) {
        scanf("%lf", &numero);

        if (numero > 0.0) q++;
    }

    printf("%d valores positivos\n", q);

    return 0;
}
