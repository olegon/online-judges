#include <stdio.h>

unsigned long long int diferenca(unsigned long long int a, unsigned long long int b);

int main (void) {
    // Min 64 bits
    unsigned long long int a, b;

    while (scanf("%llu %llu\n", &a, &b) != EOF) {
        printf("%llu\n", diferenca(a, b));
    }

    return 0;
}

unsigned long long int diferenca(unsigned long long int a, unsigned long long int b) {
    if (a > b) {
        return a - b;
    }
    else {
        return b - a;
    }
}
