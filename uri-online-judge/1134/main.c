/*
Tipo de Combustível
https://www.urionlinejudge.com.br/judge/pt/problems/view/1134
*/

#include <stdio.h>

int main (void) {
    int tipo,
        alcool = 0,
        gasolina = 0,
        diesel = 0;

    while (scanf("%d\n", &tipo), tipo != 4) {
        switch (tipo) {
            case 1:
                alcool++;
                break;
            case 2:
                gasolina++;
                break;
            case 3:
                diesel++;
                break;
        }
    }

    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\n", alcool);
    printf("Gasolina: %d\n", gasolina);
    printf("Diesel: %d\n", diesel);

    return 0;
}
