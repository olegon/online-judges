#include <stdio.h>

void imprimirAtrasoMaximo(int hora, int minuto);

int main (void) {
    int hora,
        minuto;

    while (scanf("%d:%d\n", &hora, &minuto) != EOF) {
        imprimirAtrasoMaximo(hora, minuto);
    }

    return 0;
}

void imprimirAtrasoMaximo(int hora, int minuto) {
    hora += 1;

    if (hora >= 8) {
        printf("Atraso maximo: %d\n", (hora - 8) * 60 + minuto);
    }
    else {
        printf("Atraso maximo: 0\n");
    }
}
