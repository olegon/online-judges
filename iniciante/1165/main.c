#include <stdio.h>
#include <math.h>

int ehPrimo(int n);

int main (void) {
    int casos,
        n;

    scanf("%d", &casos);

    while (casos-- > 0) {
        scanf("%d", &n);

        if (ehPrimo(n)) {
            printf("%d eh primo\n", n);
        }
        else {
            printf("%d nao eh primo\n", n);
        }
    }

    return 0;
}

int ehPrimo(int n) {
    int i,
        ate;

    if (n < 2) {
        return 0;
    }
    else if (n == 2) {
        return 1;
    }
    else if (n % 2 == 0) {
        return 0;
    }
    else {
        ate = sqrt(n) + 1;

        for (i = 3; i < ate; i += 2) {
            if (n % i == 0) {
                return 0;
            }
        }

        return 1;
    }
}
