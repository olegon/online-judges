#include <stdio.h>

int main (void) {
    int casos;

    int quantidade,
        coelhos = 0,
        ratos = 0,
        sapos = 0,
        total;

    char tipo;

    scanf("%d\n", &casos);

    while(casos-- > 0) {
        scanf("%d %c\n", &quantidade, &tipo);

        switch (tipo) {
            case 'C':
                coelhos += quantidade;
                break;
            case 'R':
                ratos += quantidade;
                break;
            case 'S':
                sapos += quantidade;
        }
    }

    total = coelhos + ratos + sapos;

    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", coelhos);
    printf("Total de ratos: %d\n", ratos);
    printf("Total de sapos: %d\n", sapos);
    printf("Percentual de coelhos: %.2f %%\n", coelhos * 100.0 / total);
    printf("Percentual de ratos: %.2f %%\n", ratos * 100.0 / total);
    printf("Percentual de sapos: %.2f %%\n", sapos * 100.0 / total);


    return 0;
}
