/*
Lucro
https://www.urionlinejudge.com.br/judge/pt/problems/view/1310
*/

#include <stdio.h>

#define MAXIMO_DE_DIAS 50

#define MAX(A,B) ((A > B) ? (A) : (B))

int analisar(int *lucros, int quantidadeDeDias, int custoPorDia);

int main (void) {
    int DIAS, CUSTO_POR_DIA;

    while (scanf("%d %d\n", &DIAS, &CUSTO_POR_DIA) != EOF) {
        int LUCROS[MAXIMO_DE_DIAS];
        int i;

        for (i = 0; i < DIAS; i++) {
            scanf("%d\n", LUCROS + i);
        }

        printf("%d\n", analisar(LUCROS, DIAS, CUSTO_POR_DIA));
    }

    return 0;
}

int analisar(int *lucros, int quantidadeDeDias, int custoPorDia) {
    int maximo = 0;
    int maximoAteAqui = 0;
    int dia;

    for (dia = 0; dia < quantidadeDeDias; dia++) {
        int lucro = lucros[dia] - custoPorDia;

        maximoAteAqui = MAX(0, maximoAteAqui + lucro);
        maximo = MAX(maximo, maximoAteAqui);
    }

    return maximo;
}
