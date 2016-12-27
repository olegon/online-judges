/*
Feynman
https://www.urionlinejudge.com.br/judge/pt/problems/view/1323
*/

#include <stdio.h>

#define SIZE 100

void preencherCache(int *cache, int size);

int main (void) {
    int quadrados,
        cache[SIZE + 1];

    preencherCache(cache, SIZE);

    while (scanf("%d", &quadrados), quadrados > 0) {
        printf("%d\n", cache[quadrados]);
    }

    return 0;
}

void preencherCache(int *cache, int size) {
    int i;

    cache[1] = 1;
    for (i = 2; i <= size; i++) {
        cache[i] = i * i + cache[i - 1];
    }
}
