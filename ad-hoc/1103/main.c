/*
Alarme Despertador
https://www.urionlinejudge.com.br/judge/pt/problems/view/1103
*/

#include <stdio.h>

int main (void) {
    int horaInicial, minutoInicial,
        horaFinal, minutoFinal,
        dtHora, dtMinuto;

    while (scanf("%d %d %d %d", &horaInicial, &minutoInicial, &horaFinal, &minutoFinal),
        horaInicial != 0 || minutoInicial != 0 || horaFinal != 0 || minutoFinal != 0) {

        dtHora = horaFinal - horaInicial;
        dtMinuto = minutoFinal - minutoInicial;

        if (dtMinuto < 0) {
            dtMinuto = 60 + dtMinuto;
            dtHora -= 1;
        }

        if (dtHora < 0) {
            dtHora = 24 + dtHora;
        }

        printf("%d\n", dtHora * 60 + dtMinuto);
    }

    return 0;
}
