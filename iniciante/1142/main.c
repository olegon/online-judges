/*
PUM
https://www.urionlinejudge.com.br/judge/pt/problems/view/1142
*/

#include <stdio.h>

int main (void) {
    int n,
        p = 1,
        i;

    scanf("%d", &n);

    while (n-- > 0) {
        for (i = 0; i < 3; i++) {
            printf("%d ", p++);
        }

        p++;
        printf("PUM\n");
    }

    return 0;
}
