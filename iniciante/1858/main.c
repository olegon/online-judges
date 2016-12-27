/*
A Resposta de Theon
https://www.urionlinejudge.com.br/judge/pt/problems/view/1858
*/

#include <stdio.h>

int main (void) {
    int quantidadeDePessoas,
        i,
        pessoa,
        pessoaAtual = 50,
        indiceAtual;

    scanf("%d", &quantidadeDePessoas);

    for (i = 1; i <= quantidadeDePessoas; i++) {
        scanf("%d", &pessoa);

        if (pessoa < pessoaAtual) {
            pessoaAtual = pessoa;
            indiceAtual = i;
        }
    }

    printf("%d\n", indiceAtual);

    return 0;
}
