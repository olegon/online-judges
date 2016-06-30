#include <stdio.h>
#include <string.h>

#define QUANTIDADE_MAXIMA_DE_PALAVRAS 50
#define QUANTIDADE_MAXIMA_DE_CARACTERES 50

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    char    caracteres[QUANTIDADE_MAXIMA_DE_CARACTERES];
    int     tamanho;
} PALAVRA;

int main (void) {
    PALAVRA palavras[QUANTIDADE_MAXIMA_DE_PALAVRAS];
    int     quantidadeDePalavras,
            i,
            quantideDeEspacos,
            tamanhoDaMaiorPalavra;

    scanf("%d\n", &quantidadeDePalavras);
    while (quantidadeDePalavras != 0) {
        tamanhoDaMaiorPalavra = 0;

        for (i = 0; i < quantidadeDePalavras; i++) {
            scanf("%s\n", palavras[i].caracteres);
            palavras[i].tamanho = strlen(palavras[i].caracteres);

            tamanhoDaMaiorPalavra = MAX(tamanhoDaMaiorPalavra, palavras[i].tamanho);
        }

        for (i = 0; i < quantidadeDePalavras; i++) {
            quantideDeEspacos = tamanhoDaMaiorPalavra - palavras[i].tamanho;

            while (quantideDeEspacos-- > 0) {
                putchar(' ');
            }

            printf("%s\n", palavras[i].caracteres);
        }

        scanf("%d\n", &quantidadeDePalavras);
        if (quantidadeDePalavras != 0) {
            printf("\n");
        }
    }

    return 0;
}
