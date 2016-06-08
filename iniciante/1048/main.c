#include <stdio.h>

double obterPercentualDeReajuste(double salario);

int main (void) {
    double  salario,
            percentualDeReajuste,
            reajuste;

    scanf("%lf", &salario);

    percentualDeReajuste = obterPercentualDeReajuste(salario);

    reajuste = salario * percentualDeReajuste;

    printf("Novo salario: %.2f\n", salario + reajuste);
    printf("Reajuste ganho: %.2f\n", reajuste);
    printf("Em percentual: %.0f %%\n", percentualDeReajuste * 100);

    return 0;
}

double obterPercentualDeReajuste(double salario) {
    if (salario <= 400.0) {
        return 0.15;
    }
    else if (salario <= 800.0) {
        return 0.12;
    }
    else if (salario <= 1200.0) {
        return 0.10;
    }
    else if (salario <= 2000.00) {
        return 0.07;
    }
    else {
        return 0.04;
    }
}
