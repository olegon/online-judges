#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000

typedef struct {
    int galinhas;
    int atacado;
} SITIO;

int impar(int numero);
int proximoSitio(int sitioAtual, int quantidade);

int main (void) {
    SITIO *sitios;

    int quantidade,
        i,
        proximoAlvo,
        quantidadeDeSitiosAtacados = 0;

    double quantidadeDeGalinhas = 0;

    scanf("%d", &quantidade);

    sitios = malloc(sizeof(SITIO) * quantidade);

    for (i = 0; i < quantidade; i++) {
        scanf("%d", &sitios[i].galinhas);
        quantidadeDeGalinhas += sitios[i].galinhas;
        sitios[i].atacado = 0;
    }

    i = 0;

    while (i >= 0 && i < quantidade) {
        if (!sitios[i].atacado) {
            quantidadeDeSitiosAtacados++;
            sitios[i].atacado = 1;
        }

        proximoAlvo = proximoSitio(i, sitios[i].galinhas);

        if (sitios[i].galinhas > 0) {
            quantidadeDeGalinhas--;
            sitios[i].galinhas--;
        }

        i = proximoAlvo;
    }

    printf("%d %.0f\n", quantidadeDeSitiosAtacados, quantidadeDeGalinhas);

    free(sitios);

    return 0;
}

int impar(int numero) {
    return numero % 2 != 0;
}

int proximoSitio(int sitioAtual, int quantidade) {
    if (impar(quantidade)) {
        return sitioAtual + 1;
    }
    else {
        return sitioAtual - 1;
    }
}
