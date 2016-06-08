#include <stdio.h>

#define SIZE 100

int main (void) {
    double  n;
    int     i;

    scanf("%lf", &n);

    for (i = 0; i < SIZE; i++) {
        printf("N[%d] = %.4f\n", i, n);
        n /= 2.0;
    }

    return 0;
}
