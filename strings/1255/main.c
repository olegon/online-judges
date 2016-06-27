#include <stdio.h>

#define MAIUSCULA(c) ((c) >= 'A' && (c) <= 'Z')
#define MINUSCULA(c) ((c) >= 'a' && (c) <= 'z')
#define LETRA(c) (MAIUSCULA(c) || MINUSCULA(c))
#define LOWERCASE(c) (MAIUSCULA(c) ? (c) + 0x20 : (c))


#define SIZE_OCORRENCIAS ('z' - 'a' + 1)


#define TAMANHO_MAXIMO_DA_LINHA 256

void limpar(int *array, int size);

int main (void) {
    int     linhas,
            ocorrencias['z' - 'a' + 1],
            i,
            maiorQuantidadeDeOcorrencias;

    char    linha[TAMANHO_MAXIMO_DA_LINHA],
            *str,
            caractere;

    scanf("%d\n", &linhas);

    while (linhas-- > 0) {
        fgets(linha, TAMANHO_MAXIMO_DA_LINHA, stdin);

        limpar(ocorrencias, SIZE_OCORRENCIAS);

        maiorQuantidadeDeOcorrencias = 0;
        str = linha;
        while (caractere = *str, str++, caractere != '\0') {
            if (LETRA(caractere)) {
                caractere = LOWERCASE(caractere);
                ocorrencias[caractere - 'a']++;

                if (ocorrencias[caractere - 'a'] > maiorQuantidadeDeOcorrencias) {
                    maiorQuantidadeDeOcorrencias = ocorrencias[caractere - 'a'];
                }
            }
        }

        for (i = 0; i < SIZE_OCORRENCIAS; i++) {
            if (ocorrencias[i] == maiorQuantidadeDeOcorrencias) {
                printf("%c", 'a' + i);
            }
        }

        printf("\n");
    }

    return 0;
}

void limpar(int *array, int size) {
    while (size--, size > -1) {
        array[size] = 0;
    }
}
