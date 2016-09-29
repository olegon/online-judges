#include <stdio.h>

int analisarTrio(int a, int b, int c);

int main (void) {
    int tamanhoDaSequencia;

    while (scanf("%d", &tamanhoDaSequencia), tamanhoDaSequencia != 0) {
        int i,
            a, b, c,
            primeiro,
            segundo,
            picos = 0;

        for (i = 0; i < tamanhoDaSequencia; i++) {
            scanf("%d\n", &c);

            if (i < 2) {
                primeiro = b;
                segundo = c;
            }
            else {
                picos += analisarTrio(a, b, c);
            }

            a = b;
            b = c;
        }

        picos += analisarTrio(a, b, primeiro);
        picos += analisarTrio(c, primeiro, segundo);

        printf("%d\n", picos);
    }

    return 0;
}

int analisarTrio(int a, int b, int c) {
    // printf("(%d %d %d) -> %d\n", a, b, c, ((a > b && b <= c) || (a < b && b >= c) || (a == b && b != c)));

    if (a > b && b <= c) {
        return 1;
    }

    if (a < b && b >= c) {
        return 1;
    }

    if (a == b && b != c) {
        return 1;
    }

    return 0;
}
