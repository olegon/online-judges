#include <stdio.h>

int quantosVaiMaisUm(int a, int b, int carry);

int main (void) {
    int a, b,
        r;

    while (scanf("%d %d\n", &a, &b), a != 0 || b != 0) {
        r = quantosVaiMaisUm(a, b, 0);

        if (r == 0) {
            printf("No carry operation.\n");
        }
        else if (r == 1) {
            printf("1 carry operation.\n");
        }
        else {
            printf("%d carry operations.\n", r);
        }
    }

    return 0;
}

int quantosVaiMaisUm(int a, int b, int carry) {
    int ra, rb;

    ra = a % 10;
    rb = b % 10;

    // printf("a, b:\t\t%d %d\n", a, b);
    // printf("ra, rb:\t\t%d %d\n", ra, rb);

    if (a == 0 && b == 0) {
        return 0;
    }
    else if (ra + rb + carry > 9) {
        return 1 + quantosVaiMaisUm(a / 10, b / 10, 1);
    }
    else {
        return quantosVaiMaisUm(a / 10, b / 10, 0);
    }
}
