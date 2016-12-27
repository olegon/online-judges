/*
Soma Natural
https://www.urionlinejudge.com.br/judge/pt/problems/view/1805
*/

#include <stdio.h>

int main (void) {
    unsigned long long int A, B;

    scanf("%llu %llu", &A, &B);

    printf("%d\n", (A + B) * (B - A + 1) / 2);

    return 0;
}
