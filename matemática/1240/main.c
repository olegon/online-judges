#include <stdio.h>
#include <math.h>


int obterDivisor(int n);

int main (void) {
    int casos,
        a,
        b;

    scanf("%d", &casos);

    while (casos-- > 0) {
        scanf("%d %d\n", &a, &b);

        if (a % obterDivisor(b) == b) {
            printf("encaixa\n");
        }
        else {
            printf("nao encaixa\n");
        }
    }

    return 0;
}


int obterDivisor(int n) {
    if (n < 10) {
        return 10;
    }
    else {
        return 10 * obterDivisor(n / 10);
    }
}
