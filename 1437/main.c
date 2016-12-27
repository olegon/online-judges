/*
Esquerda, Volver!
https://www.urionlinejudge.com.br/judge/pt/problems/view/1437
*/

#include <stdio.h>

#define ABS(n) ((n) < 0 ? -(n) : (n))

#define STRING_SIZE 1024

void imprimirDirecao(int direcaoDaFace);

int main (void) {
    int     quantidadeDeComandos,
            i,
            direcaoDaFace;
    char    comandos[STRING_SIZE];

    while (scanf("%d\n", &quantidadeDeComandos), quantidadeDeComandos != 0) {
        scanf("%s\n", comandos);

        direcaoDaFace = 0;

        for (i = 0; i < quantidadeDeComandos; i++) {
            if (comandos[i] == 'D') {
                direcaoDaFace++;
            }
            else {
                direcaoDaFace--;
            }
        }

        imprimirDirecao(direcaoDaFace);
    }

    return 0;
}

void imprimirDirecao(int direcaoDaFace) {
    direcaoDaFace = direcaoDaFace % 4;
    direcaoDaFace = direcaoDaFace < 0 ? 4 + direcaoDaFace : direcaoDaFace;

    switch (direcaoDaFace) {
        case 0:
            printf("N\n");
            break;
        case 1:
            printf("L\n");
            break;
        case 2:
            printf("S\n");
            break;
        case 3:
            printf("O\n");
            break;
    }
}
