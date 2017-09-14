/*
Tri-du
https://www.urionlinejudge.com.br/judge/pt/problems/view/1933
*/

#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main (void) {
    int a, b;

    scanf("%d %d", &a, &b);

    printf("%d\n", MAX(a, b));

    return 0;
}
