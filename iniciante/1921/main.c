#include <stdio.h>

// diagonais = (lados * (lados - 3)) / 2;

int main (void) {
    double lados;

    scanf("%lf", &lados);

    printf("%.0f\n", (lados * (lados - 3)) / 2);

    return 0;
}
