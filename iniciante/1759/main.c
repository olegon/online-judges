/*
Ho Ho Ho
https://www.urionlinejudge.com.br/judge/pt/problems/view/1759
*/

#include <stdio.h>

int main (void) {
    int n;

    scanf("%d", &n);

    while (n-- > 0) {
        printf("Ho");

        if (n == 0) {
            printf("!\n");
        }
        else {
            printf(" ");
        }
    }

    return 0;
}
