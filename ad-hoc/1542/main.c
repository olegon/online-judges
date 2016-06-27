#include <stdio.h>

int main (void) {
    double  quantidadeDePaginasLidas,
            quantidadeDeDias,
            quantidadeDePaginas;

    int total;

    while (scanf("%lf %lf %lf\n", &quantidadeDePaginasLidas, &quantidadeDeDias, &quantidadeDePaginas) == 3) {

        total = (quantidadeDePaginasLidas * quantidadeDeDias) / (quantidadeDePaginasLidas - quantidadeDePaginas) * quantidadeDePaginas * - 1.0;

        if (total == 1) {
            printf("1 pagina\n");
        }
        else {
            printf("%d paginas\n", total);
        }

    }

    return 0;
}
