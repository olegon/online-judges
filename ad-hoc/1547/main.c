#include <stdio.h>

#define ABS(n) ((n) < 0 ? -(n) : (n))

int main (void) {
    int sorteios,
        alunos,
        i,
        segredo,
        tentativa,
        diferencaEntreTentativaSegredo,
        melhorDiferenca,
        alunoDaMelhorDiferenca;

    scanf("%d", &sorteios);

    while (sorteios-- > 0) {
        scanf("%d %d", &alunos, &segredo);

        scanf("%d", &tentativa);

        melhorDiferenca = segredo - tentativa;
        melhorDiferenca = ABS(melhorDiferenca);

        alunoDaMelhorDiferenca = 1;

        for (i = 2; i <= alunos; i++) {
            scanf("%d", &tentativa);
            
            diferencaEntreTentativaSegredo = segredo - tentativa;
            diferencaEntreTentativaSegredo = ABS(diferencaEntreTentativaSegredo);

            if (diferencaEntreTentativaSegredo < melhorDiferenca) {
                melhorDiferenca = diferencaEntreTentativaSegredo;
                alunoDaMelhorDiferenca = i;
            }
        }

        printf("%d\n", alunoDaMelhorDiferenca);
    }

    return 0;
}
