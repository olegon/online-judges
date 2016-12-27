/*
Etiquetas Coloridas
https://www.urionlinejudge.com.br/judge/pt/problems/view/2233
*/

#include <stdio.h>

int main (void) {
    int ladoDoVermelho, ladoDoVerde, ladoDoAzul;
    long long int quantidadeDeVermelho, quantidadeDeVerde, quantidadeDeAzul;

    scanf("%x %x %x", &ladoDoVermelho, &ladoDoVerde, &ladoDoAzul);

    quantidadeDeVermelho = 1;

    quantidadeDeVerde = ladoDoVermelho / ladoDoVerde;
    quantidadeDeVerde *= quantidadeDeVerde;

    quantidadeDeAzul = ladoDoVerde / ladoDoAzul;
    quantidadeDeAzul *= quantidadeDeAzul;
    quantidadeDeAzul *= quantidadeDeVerde;

    printf("%llx\n", quantidadeDeVermelho + quantidadeDeVerde + quantidadeDeAzul);

    return 0;
}
