/*
Senha Fixa
https://www.urionlinejudge.com.br/judge/pt/problems/view/1114
*/

#include <stdio.h>

#define SENHA_VALIDA 2002

int main (void) {
    int senha;

    while (scanf("%d\n", &senha), senha != SENHA_VALIDA) {
        printf("Senha Invalida\n");
    }

    printf("Acesso Permitido\n");

    return 0;
}
