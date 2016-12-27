/*
Imposto de Renda
https://www.urionlinejudge.com.br/judge/pt/problems/view/1051
*/

#include <stdio.h>

double calcularIR(double salario);

int main (void) {
    double salario, IR;

    scanf("%lf", &salario);

    IR = calcularIR(salario);

    if (IR == 0.0) {
        printf("Isento\n");
    }
    else {
        printf("R$ %.2f\n", IR);
    }

    return 0;
}

double calcularIR(double salario) {
    if (salario <= 2000.0) {
        return 0;
    }
    else if (salario <= 3000.0){
        return (salario - 2000.0) * 0.08;
    }
    else if (salario <= 4500.0) {
        return calcularIR(3000.0) + (salario - 3000.0) * 0.18;
    }
    else {
        return calcularIR(4500.0) + (salario - 4500.0) * 0.28;
    }
}
