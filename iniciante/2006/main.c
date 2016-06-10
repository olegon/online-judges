#include <stdio.h>

#define QUANTIDADE_DE_CHAS 5

int main (void) {
    int chaDeExemplo,
        cha,
        quantidadeQueSeRepete = 0,
        i;

    scanf("%d", &chaDeExemplo);

    for (i = 0; i < QUANTIDADE_DE_CHAS; i++) {
        scanf("%d", &cha);

        if (cha == chaDeExemplo) {
            quantidadeQueSeRepete++;
        }
    }

    printf("%d\n", quantidadeQueSeRepete);

    return 0;
}
