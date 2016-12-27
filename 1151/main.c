/*
Fibonacci Fácil
https://www.urionlinejudge.com.br/judge/pt/problems/view/1151
*/

#include <stdio.h>

int nthFib(int n);

int main (void) {
    int nth;

    scanf("%d", &nth);

    nthFib(nth);

    return 0;
}

int nthFib(int n) {
    long unsigned int values[50] = { 0, 1 };
    int i;

    for (i = 2; i < n; i++) {
        values[i] = values[i - 1] + values[i - 2];
    }

    for (i = 0; i < n; i++) {
        printf("%lu%c", values[i], i + 1 == n ? '\n' : ' ');
    }

    return values[n - 1];
}
