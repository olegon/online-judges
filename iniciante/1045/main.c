/*
Tipos de Triângulos
https://www.urionlinejudge.com.br/judge/pt/problems/view/1045
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);

int main (void) {
    double v[3];
    int i;

    for (i = 0; i < 3; i++) {
        scanf("%lf", &v[i]);
    }

    qsort(v, 3, sizeof(double), compare);

    double  a = v[0],
            b = v[1],
            c = v[2];

    if (a >= b + c) {
        printf("NAO FORMA TRIANGULO\n");
    }
    else  {
        double  a2 = a * a,
                b2 = b * b,
                c2 = c * c;

        if (a2 == b2 + c2) {
            printf("TRIANGULO RETANGULO\n");
        }
        else if (a2 > b2 + c2) {
            printf("TRIANGULO OBTUSANGULO\n");
        }
        else  {
            printf("TRIANGULO ACUTANGULO\n");
        }

        if (a == b && b == c) {
            printf("TRIANGULO EQUILATERO\n");
        }
        else if (a == b || b == c) {
            printf("TRIANGULO ISOSCELES\n");
        }
    }

    return 0;
}

int compare(const void *a, const void *b) {
    double diff = *(double*)a - *(double*)b;

    if (diff < 0) {
        return 1;
    }
    else if (diff > 0){
        return -1;
    }
    else {
        return 0;
    }
}
