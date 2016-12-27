/*
Soma de Fatoriais
https://www.urionlinejudge.com.br/judge/pt/problems/view/1161
*/

#include <stdio.h>
#include <math.h>


unsigned long long int cache[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000, 2432902008176640000 };

unsigned long long int fatorial(int n);

int main (void) {
    int a, b;

    while (scanf("%d %d\n", &a, &b) != EOF) {
        printf("%llu\n", fatorial(a) + fatorial(b));
    }

    return 0;
}

unsigned long long int fatorial(int n) {
    return cache[n];
}
