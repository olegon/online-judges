#include <stdio.h>

int main (void) {
    int escolheuPar,
        numeroDoJogador01,
        numeroDoJogador02,
        roubou,
        acusou;

    int vitoria;

    scanf("%d %d %d %d %d",
        &escolheuPar,
        &numeroDoJogador01,
        &numeroDoJogador02,
        &roubou,
        &acusou);

    // Se deu par
    if ((numeroDoJogador01 + numeroDoJogador02) % 2 == 0) {
        if (escolheuPar) {
            vitoria = 1;
        }
        else {
            vitoria = 2;
        }
    }
    // Se deu impar
    else {
        if (escolheuPar) {
            vitoria = 2;
        }
        else {
            vitoria = 1;
        }
    }


    if (roubou) {
        if (acusou) {
            printf("Jogador 2 ganha!\n");
        }
        else {
            printf("Jogador 1 ganha!\n");
        }
    }
    else {
        // Se a vitória for do jogador 1
        if (vitoria == 1) {
            printf("Jogador 1 ganha!\n");
        }
        else {
            printf("Jogador 2 ganha!\n");
        }
    }


    return 0;
}
