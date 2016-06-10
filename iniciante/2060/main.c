#include <stdio.h>

int main (void) {
    int casos,
        numero,
        multiplosDe2 = 0,
        multiplosDe3 = 0,
        multiplosDe4 = 0,
        multiplosDe5 = 0;

    scanf("%d\n", &casos);

    while (casos-- > 0) {
        scanf("%d\n", &numero);

        if (numero % 2 == 0) {
            multiplosDe2++;
        }

        if (numero % 3 == 0) {
            multiplosDe3++;
        }

        if (numero % 4 == 0) {
            multiplosDe4++;
        }

        if (numero % 5 == 0) {
            multiplosDe5++;
        }
    }

    printf("%d Multiplo(s) de 2\n", multiplosDe2);
    printf("%d Multiplo(s) de 3\n", multiplosDe3);
    printf("%d Multiplo(s) de 4\n", multiplosDe4);
    printf("%d Multiplo(s) de 5\n", multiplosDe5);

    return 0;
}
