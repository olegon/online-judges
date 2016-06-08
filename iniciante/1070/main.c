#include <stdio.h>

int main (void) {
    int numero,
        i;

    scanf("%d", &numero);

    numero = numero % 2 == 0 ? numero + 1 : numero;

    for  (i = 0; i < 6; numero += 2, i++) {
        printf("%d\n", numero);
    }

    return 0;
}
