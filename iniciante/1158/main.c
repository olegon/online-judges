#include <stdio.h>

int main (void) {
    int n,
        x, y,
        soma;

    scanf("%d", &n);

    while (n-- > 0) {
        scanf("%d %d\n", &x, &y);

        soma = 0;

        if (x % 2 == 0) {
            x++;
        }

        while (y-- > 0) {
            soma += x;
            x += 2;
        }

        printf("%d\n", soma);
    }

    return 0;
}
