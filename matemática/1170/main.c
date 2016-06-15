#include <stdio.h>
#include <math.h>

int dias (double dias);

int main (void) {
    int     casos;
    double  comidaDisponivel;

    scanf("%d", &casos);

    while (casos-- > 0) {
        scanf("%lf", &comidaDisponivel);

        // printf("%.0f dias\n", floor(log(comidaDisponivel) / log(2)));
        printf("%d dias\n", dias(comidaDisponivel));
    }

    return 0;
}

int dias (double dias) {
    if (dias <= 1.0) {
        return 0;
    }
    else if (dias <= 2.0) {
        return 1;
    }
    else if (dias <= 4.0) {
        return 2;
    }
    else if (dias <= 8.0) {
        return 3;
    }
    else if (dias <= 16.0) {
        return 4;
    }
    else if (dias <= 32.0) {
        return 5;
    }
    else if (dias <= 64.0) {
        return 6;
    }
    else if (dias <= 128.0) {
        return 7;
    }
    else if (dias <= 256.0) {
        return 8;
    }
    else if (dias <= 512.0) {
        return 9;
    }
    else if (dias <= 1024.0) {
        return 10;
    }
    else {
        return -1;
    }
}
