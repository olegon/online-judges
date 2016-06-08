#include <stdio.h>
#include <math.h>

#define SIZE 128

int main (void) {
    int largura,
        comprimento,
        porcentagem;

    while (scanf("%d %d %d\n", &largura, &comprimento, &porcentagem) == 3) {
        printf("%.0f\n", floor(sqrt((largura * comprimento) / (porcentagem / 100.0))));
    }

    return 0;
}
