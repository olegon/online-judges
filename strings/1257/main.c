/*
Array Hash
https://www.urionlinejudge.com.br/judge/pt/problems/view/1257
*/

#include <stdio.h>

#define POSICAO_DA_LETRA(c) ((c) - 'A')

#define MAX_STRING_SIZE 64

int main (void) {
    int     casos,
            quantidadeDeLinhas,
            indiceDaLinha,
            indiceDaPalavra,
            hash;

    char    palavra[MAX_STRING_SIZE];

    scanf("%d\n", &casos);

    while (casos-- > 0) {
        hash = 0;

        scanf("%d\n", &quantidadeDeLinhas);

        for (indiceDaLinha = 0; indiceDaLinha < quantidadeDeLinhas; indiceDaLinha++) {
            scanf("%s\n", palavra);

            indiceDaPalavra = 0;
            while (palavra[indiceDaPalavra] != '\0') {
                hash += POSICAO_DA_LETRA(palavra[indiceDaPalavra]) + indiceDaLinha + indiceDaPalavra;

                indiceDaPalavra++;
            }
        }

        printf("%d\n", hash);
    }

    return 0;
}
