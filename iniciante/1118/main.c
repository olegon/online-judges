/*
Validação de Nota
https://www.urionlinejudge.com.br/judge/pt/problems/view/1117
*/

#include <stdio.h>

int main (void) {
    double  nota,
            soma;

    int quantidadeDeNotasValidas,
        opcao;

    do {
        soma = 0.0;
        quantidadeDeNotasValidas = 0;

        while (quantidadeDeNotasValidas < 2) {
            scanf("%lf\n", &nota);

            if (nota < 0 || nota > 10) {
                printf("nota invalida\n");
            }
            else {
                soma += nota;
                quantidadeDeNotasValidas++;
            }
        }

        printf("media = %.2f\n", soma / 2);

        do {
            printf("novo calculo (1-sim 2-nao)\n");
            scanf("%d\n", &opcao);
        } while (opcao != 1 && opcao != 2);

        if (opcao == 2) {
            break;
        }

    } while (1);

    return 0;
}
