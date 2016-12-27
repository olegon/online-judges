/*
De Dentro para Fora
https://www.urionlinejudge.com.br/judge/pt/problems/view/1235
*/

#include <stdio.h>
#include <string.h>

#define STRING_SIZE 128

void imprimirCorretamente(const char *str);

int main (void) {
    int     casos;
    char    str[STRING_SIZE];

    scanf("%d%*c", &casos);
    // gets(str);

    while (casos-- > 0) {
        fgets(str, STRING_SIZE, stdin);

        imprimirCorretamente(str);
    }

    return 0;
}

void imprimirCorretamente(const char *str) {
    int     length,
            half,
            i;

    // -1 para desconsiderar o \n
    length = strlen(str) - 1;
    half = length / 2;

    for (i = half - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    for (i = length - 1; i >= half; i--) {
        printf("%c", str[i]);
    }

    printf("\n");
}
