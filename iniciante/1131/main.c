#include <stdio.h>

int main (void) {
    int vitoriasDoInter = 0,
        vitoriasDoGremio = 0,
        empates = 0;

    int golsDoInter,
        golsDoGremio;

    int novoGrenal;

    do {
        scanf("%d %d\n", &golsDoInter, &golsDoGremio);

        if (golsDoInter == golsDoGremio) {
            empates++;
        }
        else if (golsDoInter > golsDoGremio) {
            vitoriasDoInter++;
        }
        else {
            vitoriasDoGremio++;
        }

        printf("Novo grenal (1-sim 2-nao)\n");

        scanf("%d\n", &novoGrenal);
    } while (novoGrenal == 1);

    printf("%d grenais\n", vitoriasDoInter + vitoriasDoGremio + empates);
    printf("Inter:%d\n", vitoriasDoInter);
    printf("Gremio:%d\n", vitoriasDoGremio);
    printf("Empates:%d\n", empates);

    if (vitoriasDoInter == vitoriasDoGremio) {
        printf("Nao houve vencedor\n");
    }
    else if (vitoriasDoInter > vitoriasDoGremio) {
        printf("Inter venceu mais\n");
    }
    else {
        printf("Gremio venceu mais\n");
    }

    return 0;
}
