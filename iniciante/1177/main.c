/*
Preenchimento de Vetor II
https://www.urionlinejudge.com.br/judge/pt/problems/view/1177
*/

#include <stdio.h>

#define SIZE 1000

int main (void) {
    int i,
        n;

    scanf("%d", &n);

    for (i = 0; i < SIZE; i++) {
        printf("N[%d] = %d\n", i, i % n);
    }

    return 0;
}
