/*
Pares e Ímpares
https://www.urionlinejudge.com.br/judge/pt/problems/view/1259
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

int comp(const void *a, const void *b);

int main (void) {
    int casos,
        numeros[SIZE],
        i;

    scanf("%d\n", &casos);

    for (i = 0; i < casos; i++) {
        scanf("%d\n", &numeros[i]);
    }

    qsort(numeros, casos, sizeof(int), comp);

    for (i = 0; i < casos; i++) {
        printf("%d\n", numeros[i]);
    }

    return 0;
}

int comp(const void *a, const void *b) {
    int ia,
        ib;

    ia = *(int*)a;
    ib = *(int*)b;

    if (ia % 2 == 0 && ib % 2 == 0) {
        return ia - ib;
    }
    else if (ia % 2 == 0) {
        return -1;
    }
    else if (ib % 2 == 0) {
        return 1;
    }
    else {
        return ib - ia;
    }
}
