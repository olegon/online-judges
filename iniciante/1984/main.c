/*
O Enigma do Pronalândia
https://www.urionlinejudge.com.br/judge/pt/problems/view/1984
*/

#include <stdio.h>

void imprimirInverso(const char *str);

#define STRING_SIZE 32

int main (void) {
    char numero[STRING_SIZE];

    scanf("%s", numero);

    imprimirInverso(numero);
    printf("\n");

    return 0;
}

void imprimirInverso(const char *str) {
    if (str[0] == '\0') {
        return;
    }
    else {
        imprimirInverso(str + 1);
        printf("%c", str[0]);
    }
}
