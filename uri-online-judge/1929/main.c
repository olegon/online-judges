/*
Triângulo
https://www.urionlinejudge.com.br/judge/pt/problems/view/1929
*/

#include <stdio.h>

int formaTriangulo(int a, int b, int c);

int main (void) {
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (formaTriangulo(a, b, c)
        || formaTriangulo(a, b, d)
        || formaTriangulo(a, c, d)
        || formaTriangulo(b, c, d)) {
        printf("S\n");
    }
    else {
        printf("N\n");
    }

    return 0;
}

int formaTriangulo(int a, int b, int c) {
    return a + b > c
        && b + c > a
        && a + c > b;
}
