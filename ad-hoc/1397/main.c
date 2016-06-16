#include <stdio.h>

int main (void) {
    int casos,
        jogadaA,
        jogadaB,
        pontosA,
        pontosB;

    while (scanf("%d\n", &casos), casos != 0) {
        pontosA = pontosB = 0;

        while (casos-- > 0) {
            scanf("%d %d\n", &jogadaA, &jogadaB);

            if (jogadaA > jogadaB) {
                pontosA++;
            }
            else if (jogadaB > jogadaA) {
                pontosB++;
            }
        }

        printf("%d %d\n", pontosA, pontosB);
    }

    return 0;
}
