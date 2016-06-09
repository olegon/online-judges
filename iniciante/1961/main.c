#include <stdio.h>

#define ABS(n) ((n) < 0 ? -(n) : (n))

#define QUANTIDADE_MAXIMA_DE_CANOS 128

int main (void) {
    int alturaDoPuloDoSapo,
        quantidadeDeCanos,
        diferenca,
        canos[QUANTIDADE_MAXIMA_DE_CANOS],
        i;

    scanf("%d %d", &alturaDoPuloDoSapo, &quantidadeDeCanos);

    for (i = 0; i < quantidadeDeCanos; i++) {
        scanf("%d", &canos[i]);
    }

    for (i = 1; i < quantidadeDeCanos; i++) {
        diferenca = canos[i] - canos[i - 1];
        if (ABS(diferenca) > alturaDoPuloDoSapo) {
            printf("GAME OVER\n");
            return 0;
        }
    }

    printf("YOU WIN\n");

    return 0;
}
