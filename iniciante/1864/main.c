/*
Nossos Dias Nunca Voltarão
https://www.urionlinejudge.com.br/judge/pt/problems/view/1864
*/

#include <stdio.h>

int main (void) {
    char frase[35] = "LIFE IS NOT A PROBLEM TO BE SOLVED";
    int quantidadeDeCaracteres;

    scanf("%d", &quantidadeDeCaracteres);

    frase[quantidadeDeCaracteres] = '\0';

    printf("%s\n", frase);

    return 0;
}
