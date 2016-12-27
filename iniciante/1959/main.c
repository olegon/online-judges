/*
Polígonos Regulares Simples
https://www.urionlinejudge.com.br/judge/pt/problems/view/1959
*/

#include <stdio.h>

int main (void) {
    double  lados,
            comprimento;

    scanf("%lf %lf", &lados, &comprimento);

    printf("%.0f\n", lados * comprimento);
    
    return 0;
}
