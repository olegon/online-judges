#include <stdio.h>

int main (void) {
    double  quantidadeDePaginasLidas,
            quantidadeDeDias,
            quantidadeDePaginas;

    while (scanf("%lf %lf %lf\n", &quantidadeDePaginasLidas, &quantidadeDeDias, &quantidadeDePaginas) == 3) {
        printf("%d paginas\n", (int)((quantidadeDePaginasLidas * quantidadeDeDias) / (quantidadeDePaginasLidas - quantidadeDePaginas) * quantidadeDePaginas * - 1.0));
    }

    return 0;
}
