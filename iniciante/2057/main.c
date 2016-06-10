#include <stdio.h>

int main (void) {
    int horaDaPartida,
        tempoDeViagem,
        fusoHorario,
        horaFinal;

    scanf("%d %d %d", &horaDaPartida, &tempoDeViagem, &fusoHorario);

    horaFinal = horaDaPartida + tempoDeViagem + fusoHorario;

    if (horaFinal == 24) {
        printf("0\n");
    }
    else if (horaFinal > 24) {
        printf("%d\n", horaFinal - 24);
    }
    else if (horaFinal < 0) {
        printf("%d\n", 24 + horaFinal);
    }
    else {
        printf("%d\n", horaFinal);
    }

    return 0;
}
