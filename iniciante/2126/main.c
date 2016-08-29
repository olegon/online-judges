#include <stdio.h>
#include <string.h>

#define TAMANHO_DO_NUMERO 64
#define TAMANHO_DO_PADRAO 16

int main (void) {
    char    numero[TAMANHO_DO_NUMERO],
            padrao[TAMANHO_DO_PADRAO],
            *ocorrencia,
            *ultimaOcorrencia;

    int caso = 1,
        quantidadeDeOcorrencias;

    while (scanf("%s\n", padrao) != EOF) {
        scanf("%s\n", numero);

        ocorrencia = numero;
        ultimaOcorrencia = NULL;
        quantidadeDeOcorrencias = 0;

        while (ocorrencia = strstr(ocorrencia, padrao), ocorrencia != NULL) {
            ultimaOcorrencia = ocorrencia;
            quantidadeDeOcorrencias++;
            ocorrencia++;
        }

        printf("Caso #%d:\n", caso++);
        if (quantidadeDeOcorrencias == 0) {
            printf("Nao existe subsequencia\n");
        }
        else {
            printf("Qtd.Subsequencias: %d\n", quantidadeDeOcorrencias);
            printf("Pos: %d\n", ultimaOcorrencia - numero + 1);
        }
        printf("\n");
    }

    return 0;
}
