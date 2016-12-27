/*
Combinador
https://www.urionlinejudge.com.br/judge/pt/problems/view/1238
*/

#include <stdio.h>

#define STRING_SIZE 64


int main (void) {
    int     casos;

    char    a[STRING_SIZE],
            b[STRING_SIZE];

    char    *pa,
            *pb;

    scanf("%d\n", &casos);

    while (casos-- > 0) {
        scanf("%s %s\n", a, b);

        pa = a;
        pb = b;

        while (*pa != '\0' && *pb != '\0') {
            putc(*pa, stdout);
            putc(*pb, stdout);

            pa++;
            pb++;
        }

        while (*pa != '\0') {
            putc(*pa, stdout);
            pa++;
        }

        while (*pb != '\0') {
            putc(*pb, stdout);
            pb++;
        }

        putc('\n', stdout);
    }

    return 0;
}
