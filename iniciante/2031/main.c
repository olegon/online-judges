#include <stdio.h>
#include <string.h>

typedef enum {
    AEREO,
    PEDRA,
    PAPEL,
    ATAQUE_ERROR
} TIPO_DE_ATAQUE;

typedef enum {
    JOGADOR01,
    JOGADOR02,
    AMBOS,
    NINGUEM,
    ANIQUILACAO,
    RESULTADO_ERROR
} RESULTADO;

TIPO_DE_ATAQUE obterAtaque(const char *ataque);
RESULTADO jogar(const char *ataqueDoJogador01, const char *ataqueDoJogador02);
void imprimirResultado(RESULTADO resultado);

#define STRING_SIZE 32

int main (void) {
    int casos;
    RESULTADO resultado;

    char    ataqueDoJogador01[STRING_SIZE],
            ataqueDoJogador02[STRING_SIZE];

    scanf("%d\n", &casos);

    while (casos-- > 0) {
        scanf("%s\n%s\n", ataqueDoJogador01, ataqueDoJogador02);

        resultado = jogar(ataqueDoJogador01, ataqueDoJogador02);

        imprimirResultado(resultado);
    }

    return 0;
}

TIPO_DE_ATAQUE obterAtaque(const char *ataque) {
    // pEdra
    if (ataque[1] == 'e') {
        return PEDRA;
    }

    // pApel
    if (ataque[1] == 'a') {
        return PAPEL;
    }

    // aTaque
    if (ataque[1] == 't') {
        return AEREO;
    }

    return ATAQUE_ERROR;
}

RESULTADO jogar(const char *ataqueDoJogador01, const char *ataqueDoJogador02) {
    TIPO_DE_ATAQUE  ataque01,
                    ataque02;

    ataque01 = obterAtaque(ataqueDoJogador01);
    ataque02 = obterAtaque(ataqueDoJogador02);

    switch (ataque01) {
        case AEREO: {
            switch (ataque02) {
                case AEREO:
                    return ANIQUILACAO;
                case PEDRA:
                    return JOGADOR01;
                case PAPEL:
                    return JOGADOR01;
                default:
                    return RESULTADO_ERROR;
            }
        }
        case PEDRA: {
            switch (ataque02) {
                case AEREO:
                    return JOGADOR02;
                case PEDRA:
                    return NINGUEM;
                case PAPEL:
                    return JOGADOR01;
                default:
                    return RESULTADO_ERROR;
            }
        }
        case PAPEL: {
            switch (ataque02) {
                case AEREO:
                    return JOGADOR02;
                case PEDRA:
                    return JOGADOR02;
                case PAPEL:
                    return AMBOS;
                default:
                    return RESULTADO_ERROR;
            }
        }
        default:
            return RESULTADO_ERROR;
    }
}

void imprimirResultado(RESULTADO resultado) {
    switch (resultado) {
        case JOGADOR01:
            printf("Jogador 1 venceu\n");
            return;
        case JOGADOR02:
            printf("Jogador 2 venceu\n");
            return;
        case AMBOS:
            printf("Ambos venceram\n");
            return;
        case NINGUEM:
            printf("Sem ganhador\n");
            return;
        case ANIQUILACAO:
            printf("Aniquilacao mutua\n");
            return;
        case RESULTADO_ERROR:
            fprintf(stderr, "Erro\n");
            return;
    }
}
