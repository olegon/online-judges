#include <stdio.h>

#define STRING_SIZE 16

int main (void) {
    int abas,
        acoes;

    char acao[STRING_SIZE];

    scanf("%d %d\n", &abas, &acoes);

    while (acoes-- > 0) {
        scanf("%s\n", acao);

        // fechou
        if (acao[0] == 'f') {
            // Fecha 1; Abre 2
            abas++;
        }
        // clicou
        else {
            // Fecha 1; Abre 0
            abas--;
        }
    }

    printf("%d\n", abas);

    return 0;
}
