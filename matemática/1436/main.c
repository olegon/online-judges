/*
Jogo do Tijolo
https://www.urionlinejudge.com.br/judge/pt/problems/view/1436
*/

#include <stdio.h>

int main (void) {
    int caso,
        casos,
        quantidade,
        i,
        indice,
        idade;

    scanf("%d", &casos);

    for (caso = 1; caso <= casos; caso++) {
        scanf("%d", &quantidade);

        indice = quantidade / 2;

        for (i = 0; i < quantidade; i++) {
            if (i == indice) {
                scanf("%d", &idade);
            }
            else {
                scanf("%*d");
            }
        }

        printf("Case %d: %d\n", caso, idade);
    }

    return 0;
}
