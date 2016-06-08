#include <stdio.h>

int main (void) {
    int diaInicial,
        horaInicial,
        minutoInicial,
        segundoInicial;

    int diaFinal,
        horaFinal,
        minutoFinal,
        segundoFinal;

    int diaDelta,
        horaDelta,
        minutoDelta,
        segundoDelta;

    scanf("Dia %d\n", &diaInicial);
    // printf("Dia: %d\n", diaInicial);
    scanf("%d : %d : %d\n", &horaInicial, &minutoInicial, &segundoInicial);
    // printf("Tempo: %d %d %d\n", horaInicial, minutoInicial, segundoInicial);


    scanf("Dia %d\n", &diaFinal);
    // printf("Dia: %d\n", diaFinal);
    scanf("%d : %d : %d\n", &horaFinal, &minutoFinal, &segundoFinal);
    // printf("Tempo: %d %d %d\n", horaFinal, minutoFinal, segundoFinal);

    if (segundoFinal >= segundoInicial) {
        segundoDelta = segundoFinal - segundoInicial;
    }
    else {
        segundoDelta = segundoFinal - segundoInicial + 60;
        minutoFinal--;
    }

    if (minutoFinal >= minutoInicial) {
        minutoDelta = minutoFinal - minutoInicial;
    }
    else {
        minutoDelta = minutoFinal - minutoInicial + 60;
        horaFinal--;
    }

    if (horaFinal >= horaInicial) {
        horaDelta = horaFinal - horaInicial;
    }
    else {
        horaDelta = horaFinal - horaInicial + 24;
        diaFinal--;
    }

    diaDelta = diaFinal - diaInicial;

    printf("%d dia(s)\n", diaDelta);
    printf("%d hora(s)\n", horaDelta);
    printf("%d minuto(s)\n", minutoDelta);
    printf("%d segundo(s)\n", segundoDelta);

    return 0;
}
