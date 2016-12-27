/*
Área do Círculo
https://www.urionlinejudge.com.br/judge/pt/problems/view/1002
*/

#include <stdio.h>

int main (void) {
    double r;
    double pi = 3.14159;

    scanf("%lf", &r);
    printf("A=%.4lf\n", r * r * pi);

    return 0;
}
