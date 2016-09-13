#include <stdio.h>
#include <stdlib.h>

int diff(const void *a, const void *b);

int main (void) {
    int creditos[3],
        i;

    for (i = 0; i < 3; i++) {
        scanf("%d", creditos + i);
    }

    if (creditos[0] == creditos[1] || creditos[1] == creditos[2] || creditos[0] == creditos[2]) {
        printf("S\n");
    }
    else {
        qsort(creditos, 3, sizeof(int), diff);

        if (creditos[0] + creditos[1] == creditos[2]) {
            printf("S\n");
        }
        else {
            printf("N\n");
        }
    }

    return 0;
}

int diff(const void *a, const void *b) {
    const int   *ia = a,
                *ib = b;

    return *ia - *ib;
}
