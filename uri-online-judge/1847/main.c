/*
Bem-vindos e Bem-vindas ao Inverno!
https://www.urionlinejudge.com.br/judge/pt/problems/view/1847
*/

#include <stdio.h>

#define DESCEU(a, b) ((a) > (b))
#define SUBIU(a, b) ((a) < (b))
#define IGUAL(a, b) ((a) == (b))
#define FELIZ() printf(":)\n");
#define TRISTE() printf(":(\n");
#define DIFERENCA(a, b) ((a) - (b))

int main (void) {
    int dia1,
        dia2,
        dia3;

    scanf("%d %d %d", &dia1, &dia2, &dia3);

    if (DESCEU(dia1, dia2) && (SUBIU(dia2, dia3) || IGUAL(dia2, dia3))) {
        FELIZ()
    }
    else if (SUBIU(dia1, dia2) && (DESCEU(dia2, dia3) || IGUAL(dia2, dia3))) {
        TRISTE()
    }
    else if (SUBIU(dia1, dia2) && SUBIU(dia2, dia3)) {
        if (DIFERENCA(dia2, dia3) > DIFERENCA(dia1, dia2)) {
            TRISTE()
        }
        else {
            FELIZ()
        }
    }
    else if (DESCEU(dia1, dia2) && DESCEU(dia2, dia3)) {
        if (DIFERENCA(dia2, dia3) < DIFERENCA(dia1, dia2)) {
            FELIZ()
        }
        else {
            TRISTE()
        }
    }
    else if (IGUAL(dia1, dia2)) {
        if (SUBIU(dia2, dia3)) {
            FELIZ()
        }
        else {
            TRISTE()
        }
    }

    return 0;
}
