#include <stdio.h>

int main (void) {
    int x,
        z,
        soma = 0,
        i;

    scanf("%d", &x);

    while (scanf("%d", &z), z <= x);


    for (i = 0; soma <= z; i++) {
        soma += x++;
    }

    printf("%d\n", i);

    return 0;
}
