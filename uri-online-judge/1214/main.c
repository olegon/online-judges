/*
Acima da Média
https://www.urionlinejudge.com.br/judge/pt/problems/view/1214
*/

#include <stdio.h>

#define QUANTIDADE_MAXIMA_DE_ALUNOS 1024

int main (void) {
    int     casos,
            quantidadeDeAlunos,
            i,
            notas[QUANTIDADE_MAXIMA_DE_ALUNOS],
            alunosAcimaDaMedia;
    double  media;

    scanf("%d", &casos);

    while (casos-- > 0) {
        scanf("%d", &quantidadeDeAlunos);

        media = 0.0;
        for (i = 0; i < quantidadeDeAlunos; i++) {
            scanf("%d\n", &notas[i]);
            media += notas[i];
        }

        media /= quantidadeDeAlunos;

        alunosAcimaDaMedia = 0;
        for (i = 0; i < quantidadeDeAlunos; i++) {
            if (notas[i] > media) {
                alunosAcimaDaMedia++;
            }
        }

        printf("%.3f%%\n", alunosAcimaDaMedia * 100.0 / quantidadeDeAlunos);
    }

    return 0;
}
