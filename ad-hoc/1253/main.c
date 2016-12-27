/*
Cifra de César
https://www.urionlinejudge.com.br/judge/pt/problems/view/1253
*/

#include <stdio.h>

#define STRING_SIZE 64

void imprimirDecodificado(const char *str, int chave);

int main (void) {
    int     casos,
            chave;
    char    str[STRING_SIZE];

    scanf("%d\n", &casos);

    while (casos-- > 0) {
        fgets(str, STRING_SIZE, stdin);
        scanf("%d\n", &chave);

        imprimirDecodificado(str, chave);
    }

    return 0;
}


void imprimirDecodificado(const char *str, int chave) {
    char caractere;

    while (caractere = *str, str++, caractere != '\n') {
        caractere -= chave;

        if (caractere < 'A') {
            caractere = 'Z' - ('A' - caractere) + 1;
        }

        putc(caractere, stdout);
    }

    putc('\n', stdout);
}
