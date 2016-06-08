#include <stdio.h>

int main (void) {
    int n,
        i,
        quadrado,
        cubo;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        quadrado = i * i;
        cubo = quadrado * i;

        printf("%d %d %d\n", i, quadrado, cubo);
        printf("%d %d %d\n", i, quadrado + 1, cubo + 1);
    }

    return 0;
}
