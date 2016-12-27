/*
Números Pares
https://www.urionlinejudge.com.br/judge/pt/problems/view/1059
*/

#include <stdio.h>

int main (void) {
    int i;

    for (i = 2; i < 101; i += 2) {
        printf("%d\n", i);
    }

    return 0;
}
