/*
Soma de Ímpares Consecutivos II
https://www.urionlinejudge.com.br/judge/pt/problems/view/1099
*/

#include <stdio.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main (void) {
    int n,
        i;

    int x,
        y;

    int min,
        max;

    int sum;

    scanf("%d\n", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d\n", &x, &y);

        min = MIN(x, y);
        max = MAX(x, y);

        min = min % 2 == 0 ? min + 1 : min + 2;

        sum = 0;
        while (min < max) {
            sum += min;
            min += 2;
        }

        printf("%d\n", sum);
    }

    return 0;
}
