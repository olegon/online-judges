#include <stdio.h>

int rafaelFn(int x, int y);
int betoFn(int x, int y);
int carlosFn(int x, int y);

int main (void) {
    int casos,
        x,
        y,
        rafaelResult,
        betoResult,
        carlosResult;

    scanf("%d", &casos);

    for (; casos > 0; casos--) {
        scanf("%d %d", &x, &y);

        rafaelResult = rafaelFn(x, y);
        betoResult = betoFn(x, y);
        carlosResult = carlosFn(x, y);

        // Assuma que nunca haverá empates.

        if (rafaelResult > betoResult && rafaelResult > carlosResult) {
            printf("Rafael ganhou\n");
        }
        else if (betoResult > rafaelResult && betoResult > carlosResult) {
            printf("Beto ganhou\n");
        }
        else {
            printf("Carlos ganhou\n");
        }
    }

    return 0;
}

int rafaelFn(int x, int y) {
    return 9 * x * x + y * y;
}

int betoFn(int x, int y) {
    return 2 * x * x + 25 * y * y;
}

int carlosFn(int x, int y) {
    return -100 * x + y * y * y;
}
