#include <stdio.h>

double obterValor(int codigo);

int main (void) {
    int     totalDeItensComprados,
            codigoDoProduto,
            quantidadeDeItensDoProduto;
    double  valorTotal = 0.0;

    scanf("%d", &totalDeItensComprados);

    while (totalDeItensComprados-- > 0) {
        scanf("%d %d", &codigoDoProduto, &quantidadeDeItensDoProduto);

        valorTotal += obterValor(codigoDoProduto) * quantidadeDeItensDoProduto;
    }

    printf("%.2f\n", valorTotal);

    return 0;
}

double obterValor(int codigo) {
    switch (codigo) {
        case 1001:
            return 1.50;
        case 1002:
            return 2.50;
        case 1003:
            return 3.50;
        case 1004:
            return 4.50;
        case 1005:
            return 5.50;
        default:
            return 0.0;
    }
}
