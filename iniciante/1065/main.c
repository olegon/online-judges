#include <stdio.h>

int main (void) {
    int i, q = 0;
    int numero;

    for (i = 0; i < 5; i++) {
        scanf("%d", &numero);

        if (numero % 2 == 0) q++;
    }

    printf("%d valores pares\n", q);

    return 0;
}
