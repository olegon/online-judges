#include <stdio.h>

char obterAlternativaSelecionada(int *alternativas, int quantidadeDeAlternativas);

#define MARCADA(alternativa) ((alternativa) <= 127)

#define QUANTIDADE_DE_ALTERNATIVAS 5

int main (void) {
    int casos,
        i,
        alternativas[QUANTIDADE_DE_ALTERNATIVAS];

    while (scanf("%d", &casos), casos != 0) {
        while (casos-- > 0) {
            for (i = 0; i < QUANTIDADE_DE_ALTERNATIVAS; i++) {
                scanf("%d", &alternativas[i]);
            }

            printf("%c\n", obterAlternativaSelecionada(alternativas, QUANTIDADE_DE_ALTERNATIVAS));
        }
    }

    return 0;
}

char obterAlternativaSelecionada(int *alternativas, int quantidadeDeAlternativas) {
    int i,
        alternativaSelecionada = -1;

    for (i = 0; i < quantidadeDeAlternativas; i++) {
        if (MARCADA(alternativas[i])) {
            if (alternativaSelecionada == -1) {
                alternativaSelecionada = i;
            }
            else {
                return '*';
            }
        }
    }

    if (alternativaSelecionada == -1) {
        return '*';
    }
    else {
        return 'A' + alternativaSelecionada;
    }
}
