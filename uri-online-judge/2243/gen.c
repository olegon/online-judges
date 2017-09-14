#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {
    int N,
        i;

    N = 5e4;

    printf("%d\n", N);

    srand(time(NULL));

    for (i = 0; i < N; i++) {
        printf("%d ", rand() % N + 1);
    }

    printf("\n");

    return 0;
}
