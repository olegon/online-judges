#include <stdio.h>

#define SIZE 100

int main (void) {
    double  a[SIZE];
    int     i;

    for (i = 0; i < SIZE; i++) {
        scanf("%lf", &a[i]);

        if (a[i] <= 10.0) {
            printf("A[%d] = %.1f\n", i, a[i]);
        }
    }

    return 0;
}
