/*
Fila do Recreio
https://www.urionlinejudge.com.br/judge/pt/problems/view/1548
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXIMO_DE_ALUNOS 1024

typedef struct {
    int nota;
    int posicaoInicial;
} ALUNO;

int comp(const void *a, const void *b);

int main (void) {
    int casos,
        quantidadeDeAlunos,
        i,
        quantidadeDeAlunosQueNaoTrocaramDeLugar;

    ALUNO alunos[MAXIMO_DE_ALUNOS];

    scanf("%d", &casos);

    while (casos-- > 0) {
        scanf("%d", &quantidadeDeAlunos);

        for (i = 0; i < quantidadeDeAlunos; i++) {
            scanf("%d\n", &alunos[i].nota);
            alunos[i].posicaoInicial = i;
        }

        qsort(alunos, quantidadeDeAlunos, sizeof(ALUNO), comp);

        quantidadeDeAlunosQueNaoTrocaramDeLugar = 0;
        for (i = 0; i < quantidadeDeAlunos; i++) {
            if (i == alunos[i].posicaoInicial) {
                quantidadeDeAlunosQueNaoTrocaramDeLugar++;
            }
        }

        printf("%d\n", quantidadeDeAlunosQueNaoTrocaramDeLugar);
    }



    return 0;
}

int comp(const void *a, const void *b) {
    const ALUNO *aluno_a = a,
                *aluno_b = b;

    return aluno_b->nota - aluno_a->nota;
}
