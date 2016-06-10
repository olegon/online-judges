#include <stdio.h>

#define PI 3.14



int main (void) {
    double  volume,
            diametro,
            raio,
            area;

    while (scanf("%lf\n%lf\n", &volume, &diametro) != EOF) {
        raio = diametro / 2;
        area = raio * raio * PI;

        printf("ALTURA = %.2f\n", volume / area);
        printf("AREA = %.2f\n", area);
    }

    return 0;
}
