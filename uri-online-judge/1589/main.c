/*
Bob Conduite
https://www.urionlinejudge.com.br/judge/pt/problems/view/1589
*/

#include <stdio.h>

int main (void) {
    int casos,
        a, b;

    scanf("%d", &casos);

    while (casos-- > 0) {
        scanf("%d %d", &a, &b);

        printf("%d\n", a + b);
    }

    return 0;
}
