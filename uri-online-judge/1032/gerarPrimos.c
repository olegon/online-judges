#include <stdio.h>
#include <math.h>

int isPrimo(int n);

int main (void) {
    printf("[");

    int primosCount = 0;
    size_t i = 0;
    while (primosCount < 3510) {
        while (!isPrimo(++i));

        printf(" %d,", i);
        primosCount++;
    }

    printf(" ]\n");

    return 0;
}

int isPrimo(int n) {
    int i;

    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    size_t limit = sqrt(n);

    for (i = 3; i <= limit; i += 2) {
        if (n % i == 0) return 0;
    }

    return 1;
}