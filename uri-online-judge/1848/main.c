/*
Corvo Contador
https://www.urionlinejudge.com.br/judge/pt/problems/view/1848
*/

#include <stdio.h>

#define STRING_SIZE 16
#define QUANTIDADE_DE_NUMEROS 3

int gritou(const char *str);
int obterValor(const char *str);

int main (void) {
    char    str[STRING_SIZE],
            *str_ptr;

    int     numeros[3] = { 0, 0, 0 },
            ultimoIndice = 0,
            i;

    while (str_ptr = fgets(str, STRING_SIZE, stdin), str_ptr) {
        if (gritou(str)) {
            ultimoIndice++;
        }
        else {
            numeros[ultimoIndice] += obterValor(str);
        }
    }

    for (i = 0; i < QUANTIDADE_DE_NUMEROS; i++) {
        printf("%d\n", numeros[i]);
    }

    return 0;
}

int gritou(const char *str) {
    return str[0] == 'c';
}

int obterValor(const char *str) {
    int valor = 0;

    if (str[0] == '*') {
        valor += 4;
    }

    if (str[1] == '*') {
        valor += 2;
    }

    if (str[2] == '*') {
        valor += 1;
    }

    return valor;
}
