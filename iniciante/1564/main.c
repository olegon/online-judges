/*
Vai Ter Copa?
https://www.urionlinejudge.com.br/judge/pt/problems/view/1564
*/

#include <stdio.h>

int main (void) {
    int reclamacoes;

    while (scanf("%d\n", &reclamacoes) != EOF) {
        if (reclamacoes == 0) {
            printf("vai ter copa!\n");
        }
        else {
            printf("vai ter duas!\n");
        }
    }

    return 0;
}
