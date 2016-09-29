#include <stdio.h>

#define QUANTIDADE_MAXIMA_DE_VAGOES 50

int main (void) {
    int casos;

    scanf("%d\n", &casos);

    while (casos-- > 0) {
        int quantidadeDeVagoes,
            vagoes[QUANTIDADE_MAXIMA_DE_VAGOES],
            i,
            passos = 0;

        scanf("%d", &quantidadeDeVagoes);

        for (i = 0; i < quantidadeDeVagoes; i++) {
            scanf("%d", vagoes + i);
        }

        passos = 0;

        for (i = 0; i < quantidadeDeVagoes; i++) {
            int vagaoProcurado = i + 1;

            if (vagoes[i] == vagaoProcurado) {
                continue;
            }

            int j;
            for (j = quantidadeDeVagoes - 1; j > i; j--) {
                if (vagoes[j] == vagaoProcurado) {
                    int vagao = vagoes[j];
                    vagoes[j] = vagoes[j - 1];
                    vagoes[j - 1] = vagao;

                    passos++;
                }
            }
        }

        printf("Optimal train swapping takes %d swaps.\n", passos);
    }

    return 0;
}
