#include <stdio.h>

void aplicarRegrasDoMataMata(int golsDoPrimeiroTimeNaIda, int golsDoSegundoTimeNaIda, int golsDoPrimeiroTimeNaVolta, int golsDoSegundoTimeNaVolta);

int main (void) {
    int casos,
        golsDoPrimeiroTimeNaIda, golsDoSegundoTimeNaIda,
        golsDoPrimeiroTimeNaVolta, golsDoSegundoTimeNaVolta;

    scanf("%d\n", &casos);

    while(casos-- > 0) {
        scanf("%d x %d\n", &golsDoPrimeiroTimeNaIda, &golsDoSegundoTimeNaIda);
        scanf("%d x %d\n", &golsDoSegundoTimeNaVolta, &golsDoPrimeiroTimeNaVolta);

        aplicarRegrasDoMataMata(golsDoPrimeiroTimeNaIda, golsDoSegundoTimeNaIda, golsDoPrimeiroTimeNaVolta, golsDoSegundoTimeNaVolta);
    }

    return 0;
}

void aplicarRegrasDoMataMata(int golsDoPrimeiroTimeNaIda, int golsDoSegundoTimeNaIda, int golsDoPrimeiroTimeNaVolta, int golsDoSegundoTimeNaVolta) {
    if (golsDoPrimeiroTimeNaIda > golsDoSegundoTimeNaIda && golsDoPrimeiroTimeNaVolta > golsDoSegundoTimeNaVolta) {
        printf("Time 1\n");
    }
    else if (golsDoPrimeiroTimeNaIda < golsDoSegundoTimeNaIda && golsDoPrimeiroTimeNaVolta < golsDoSegundoTimeNaVolta) {
        printf("Time 2\n");
    }
    else if (golsDoPrimeiroTimeNaIda == golsDoSegundoTimeNaIda && golsDoPrimeiroTimeNaVolta != golsDoSegundoTimeNaVolta) {
        if (golsDoPrimeiroTimeNaVolta > golsDoSegundoTimeNaVolta) {
            printf("Time 1\n");
        }
        else {
            printf("Time 2\n");
        }
    }
    else if (golsDoPrimeiroTimeNaIda != golsDoSegundoTimeNaIda && golsDoPrimeiroTimeNaVolta == golsDoSegundoTimeNaVolta) {
        if (golsDoPrimeiroTimeNaIda > golsDoSegundoTimeNaIda) {
            printf("Time 1\n");
        }
        else {
            printf("Time 2\n");
        }
    }
    else {
        int golsDoPrimeiro = golsDoPrimeiroTimeNaIda + golsDoPrimeiroTimeNaVolta;
        int golsDoSegundo = golsDoSegundoTimeNaIda + golsDoSegundoTimeNaVolta;

        if (golsDoPrimeiro == golsDoSegundo) {
            if (golsDoPrimeiroTimeNaVolta == golsDoSegundoTimeNaIda) {
                printf("Penaltis\n");
            }
            else if (golsDoPrimeiroTimeNaVolta > golsDoSegundoTimeNaIda) {
                printf("Time 1\n");
            }
            else {
                printf("Time 2\n");
            }
        }
        else if (golsDoPrimeiro > golsDoSegundo) {
            printf("Time 1\n");
        }
        else {
            printf("Time 2\n");
        }
    }
}
