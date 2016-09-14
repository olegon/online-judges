#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int divisor, naoDivisor,
        multiplo, naoMultiplo,
        tentativa;

    scanf("%d %d %d %d", &divisor, &naoDivisor, &multiplo, &naoMultiplo);

    if (multiplo % divisor != 0) {
        printf("-1\n");
    }
    else if (divisor == multiplo) {
        tentativa = divisor;

        if (tentativa % naoDivisor != 0 && naoMultiplo % tentativa != 0) {
            printf("%d\n", divisor);
        }
        else {
            printf("-1\n");

        }
    }
    else {
        for (tentativa = divisor; tentativa <= multiplo; tentativa += divisor) {
            if (tentativa % divisor == 0 && multiplo % tentativa == 0
                && tentativa % naoDivisor != 0 && naoMultiplo % tentativa != 0) {
                printf("%d\n", tentativa);
                exit(EXIT_SUCCESS);
            }
        }
    }

    printf("-1\n");

    return 0;
}
