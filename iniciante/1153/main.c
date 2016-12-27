/*
Fatorial Simples
https://www.urionlinejudge.com.br/judge/pt/problems/view/1153
*/

#include <stdio.h>

long unsigned int fatorial(int n);

int main (void) {
    int nth;

    scanf("%d", &nth);

    printf("%lu\n", fatorial(nth));

    return 0;
}

long unsigned int fatorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * fatorial(n - 1);
    }
}
