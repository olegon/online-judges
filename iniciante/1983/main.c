/*
O Escolhido
https://www.urionlinejudge.com.br/judge/pt/problems/view/1983
*/

#include <stdio.h>

int main (void) {
    int quantidadeDeAlunos;

    int matricula,
        matriculaDoMelhorAluno;

    double  nota,
            notaDoMelhorAluno = -1.0;

    scanf("%d", &quantidadeDeAlunos);

    while (quantidadeDeAlunos-- > 0) {
        scanf("%d %lf", &matricula, &nota);

        if (nota > notaDoMelhorAluno) {
            notaDoMelhorAluno = nota;
            matriculaDoMelhorAluno = matricula;
        }
    }

    if (notaDoMelhorAluno >= 8.0) {
        printf("%d\n", matriculaDoMelhorAluno);
    }
    else {
        printf("Minimum note not reached\n");
    }

    return 0;
}
