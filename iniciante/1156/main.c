#include <stdio.h>
#include <math.h>

int main (void) {
    double  t = 0;

    int numerador = 1,
        denominador_exp = 0;

    while (numerador <= 39) {
        t += numerador / pow(2, denominador_exp++);

        numerador += 2;
    }

    printf("%.2f\n", t);

    return 0;
}
