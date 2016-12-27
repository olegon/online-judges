/*
Tempo de Jogo com Minutos
https://www.urionlinejudge.com.br/judge/pt/problems/view/1047
*/

#include <stdio.h>

int main (void) {
    int horaInicial, minutoInicial,
        horaFinal, minutoFinal,
        horaDelta, minutoDelta;

    scanf("%d %d %d %d", &horaInicial, &minutoInicial, &horaFinal, &minutoFinal);

    if (horaInicial < horaFinal) {
        horaDelta = horaFinal - horaInicial;
    }
    else {
        horaDelta = 24 - (horaInicial - horaFinal);
    }

    if (minutoInicial <= minutoFinal) {
        minutoDelta = minutoFinal - minutoInicial;
    }
    else {
        minutoDelta = 60 - (minutoInicial - minutoFinal);
        horaDelta -= 1;
    }

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", horaDelta, minutoDelta);

    return 0;
}
