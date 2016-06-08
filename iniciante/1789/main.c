#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int obterNivel (int velocidade, int nivelAtual);

int main (void) {
    int casos,
        velocidade,
        nivel;

    while (scanf("%d%*c", &casos) != EOF) {
        nivel = 0;

        while (casos-- > 0) {
            scanf("%d%*c", &velocidade);

            nivel = obterNivel(velocidade, nivel);
        }

        printf("%d\n", nivel);
    }

    return 0;
}

int obterNivel (int velocidade, int nivelAtual) {
    if (velocidade < 10) {
        return MAX(1, nivelAtual);
    }
    else if (velocidade < 20) {
        return MAX(2, nivelAtual);
    }
    else {
        return 3;
    }
}
