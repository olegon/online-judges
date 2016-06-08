#include <stdio.h>

#define SIZE 20

int main (void) {
    int n[SIZE],
        i,
        aux;

    for (i = 0; i < SIZE; i++) {
        scanf("%d", &n[i]);
    }

    for (i = 0; i < SIZE / 2; i++) {
        aux = n[i];
        n[i] = n[SIZE - 1 - i];
        n[SIZE - 1 - i] = aux;
    }

    for (i = 0; i < SIZE; i++) {
        printf("N[%d] = %d\n", i, n[i]);
    }

    return 0;
}
