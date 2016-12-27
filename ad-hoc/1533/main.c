/*
Detetive Watson
https://www.urionlinejudge.com.br/judge/pt/problems/view/1533
*/

#include <stdio.h>

#define QUANTIDADE_MAXIMA_DE_SUSPEITOS 10000

int obterIndiceDoMaiorElemento(int *valores, int quantidadeDeElementos);

int main (void) {
    int quantidadeDeSuspeitos,
        suspeitos[10000],
        i,
        indiceDoMaisSuspeito;

    while (scanf("%d", &quantidadeDeSuspeitos), quantidadeDeSuspeitos != 0) {
        for (i = 0; i < quantidadeDeSuspeitos; i++) {
            scanf("%d", &suspeitos[i]);
        }

        indiceDoMaisSuspeito = obterIndiceDoMaiorElemento(suspeitos, quantidadeDeSuspeitos);
        suspeitos[indiceDoMaisSuspeito] = -1;
        indiceDoMaisSuspeito = obterIndiceDoMaiorElemento(suspeitos, quantidadeDeSuspeitos);

        printf("%d\n", indiceDoMaisSuspeito + 1);

    }

    return 0;
}

int obterIndiceDoMaiorElemento(int *valores, int quantidadeDeElementos) {
    int maiorValor,
        indiceDoMaiorValor,
        i;

    maiorValor = valores[0];
    indiceDoMaiorValor = 0;

    for (i = 1; i < quantidadeDeElementos; i++) {
        if (valores[i] > maiorValor) {
            maiorValor = valores[i];
            indiceDoMaiorValor = i;
        }
    }

    return indiceDoMaiorValor;
}
