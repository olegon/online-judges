#include <stdio.h>
#include <math.h>

int main (void) {
    int     casos;
    double  comidaDisponivel;

    scanf("%d", &casos);

    while (casos-- > 0) {
        scanf("%lf", &comidaDisponivel);

        printf("%.0f dias\n", ceil(log2(comidaDisponivel)));
    }

    return 0;
}
