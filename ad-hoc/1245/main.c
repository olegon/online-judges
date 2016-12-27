/*
Botas Perdidas
https://www.urionlinejudge.com.br/judge/pt/problems/view/1245
*/

#include <stdio.h>

#define DIREITO     'D'
#define ESQUERDO    'E'

#define MAXIMO_DE_BOTAS 31
#define NUMERO_MAXIMO 60

typedef struct {
    int direito;
    int esquerdo;
} BOTA;

int main (void) {
    int     quantidadeDeBotas,
            numero,
            i,
            total;

    BOTA    botas[MAXIMO_DE_BOTAS];

    char    pe;

    while (scanf("%d\n", &quantidadeDeBotas) != EOF) {
        for (i = 0; i < MAXIMO_DE_BOTAS; i++) {
            botas[i].direito = 0;
            botas[i].esquerdo = 0;
        }

        total = 0;
        while (quantidadeDeBotas-- > 0) {
            scanf("%d %c\n", &numero, &pe);

            if (pe == DIREITO) {
                botas[NUMERO_MAXIMO - numero].direito++;
            }
            else {
                botas[NUMERO_MAXIMO - numero].esquerdo++;
            }

            if (botas[NUMERO_MAXIMO - numero].direito > 0 && botas[NUMERO_MAXIMO - numero].esquerdo > 0) {
                botas[NUMERO_MAXIMO - numero].direito--;
                botas[NUMERO_MAXIMO - numero].esquerdo--;
                total++;
            }
        }

        printf("%d\n", total);
    }

    return 0;
}
