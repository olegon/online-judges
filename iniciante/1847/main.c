#include <stdio.h>

#define DESCEU(a, b) ((a) > (b))
#define SUBIU(a, b) ((a) < (b))
#define IGUAL(a, b) ((a) == (b))
#define FELIZ() printf(":)\n")
#define TRISTE() printf(":()\n")

int main (void) {
    int dia1,
        dia2,
        dia3;

    scanf("%d %d %d", &dia1, &dia2, &dia3);

    if (DESCEU(dia1, dia2) && (SUBIU(dia2, dia3) || IGUAL(dia2, dia3))) {
        FELIZ();
    }
    else if (SUBIU(dia1, dia2) && (DESCEU(dia2, dia3) || IGUAL(dia2, dia3))) {
        TRISTE();
    }
    else if (SUBIU(dia1, dia2) && SUBIU(dia2, dia3)) {
        if (dia3 < dia2 && ) {
            /* code */
        }
    }


    return 0;
}
