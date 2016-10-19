#include <stdio.h>

#define PINOS 5

int main (void) {
    int macho[PINOS],
        femea[PINOS],
        i,
        encaixa = 1;

    for (i = 0; i < PINOS; i++) {
        scanf("%d", macho + i);
    }

    for (i = 0; i < PINOS; i++) {
        scanf("%d", femea + i);
    }

    for (i = 0; i < PINOS; i++) {
        if (macho[i] ^ femea[i]) continue;
        else {
            encaixa = 0;
            break;
        }
    }

    if (encaixa) {
        printf("Y\n");
    }
    else {
        printf("N\n");
    }

    return 0;
}
