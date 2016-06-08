#include <stdio.h>

int main (void) {
    int x,
        i,
        soma;

    while (scanf("%d", &x), x != 0) {
        if (x % 2 != 0) {
            x++;
        }

        soma = 0;

        for (i = 0; i < 5; i++) {
            soma += x;
            x += 2;
        }

        printf("%d\n", soma);
    }

    return 0;
}
