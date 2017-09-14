/*
Fazendo Pandorgas
https://www.urionlinejudge.com.br/judge/pt/problems/view/1585
*/

#include <stdio.h>

int main (void) {
    int     casos,
            area;
    double  x, y;

    scanf("%d\n", &casos);

    while (casos-- > 0) {
        scanf("%lf %lf\n", &x, &y);

        x /= 2;
        y /= 2;

        area =  2 * x * y;

        printf("%d cm2\n", area);
    }

    return 0;
}
