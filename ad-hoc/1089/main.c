#include <stdio.h>

int main (void) {
    int tamanhoDaSequencia,
        magnitude,
        a, b, c,
        total;

    while (scanf("%d", &tamanhoDaSequencia), tamanhoDaSequencia != 0) {
        if (tamanhoDaSequencia == 2) {
            scanf("%*d %*d");
            printf("2\n");
            continue;
        }

        total = 1;
        scanf("%d %d", &b, &c);
        tamanhoDaSequencia -= 2;

        while (tamanhoDaSequencia-- > 0) {
            scanf("%d", &magnitude);

            a = b;
            b = c;
            c = magnitude;


            if ((b >= a && b > c) || (b <= a && b < c)) {
                total++;
            }

            printf("%d %d %d: %d\n", a, b, c, total);
        }

        if ((a <= b && b > c) || (a >= b && b < c)) {
            total++;
        }

        printf("%d\n\n\n", total);
    }

    return 0;
}
