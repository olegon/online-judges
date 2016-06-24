#include <stdio.h>

#define NUMERO_MAXIMO_DE_PESSSOAS 128
#define NUMERO_MAXIMO_DE_PROBLEMAS 128

#define INDICE_DA_SOMA 101

int ninguemResolveuTodosOsProblemas(int problemas[][NUMERO_MAXIMO_DE_PROBLEMAS], int numeroDeParticipantes, int numeroDeProblemas);
int todoProblemaFoiResolvidoPorPeloMenosUmaPessoa(int problemas[][NUMERO_MAXIMO_DE_PROBLEMAS], int numeroDeParticipantes, int numeroDeProblemas);
int nenhumProblemaFoiResolvidoPorTodos(int problemas[][NUMERO_MAXIMO_DE_PROBLEMAS], int numeroDeParticipantes, int numeroDeProblemas);
int todosResolveramAoMenosUmProblema(int problemas[][NUMERO_MAXIMO_DE_PROBLEMAS], int numeroDeParticipantes, int numeroDeProblemas);

int main (void) {
    int numeroDeParticipantes,
        i,
        numeroDeProblemas,
        j,
        problemas[NUMERO_MAXIMO_DE_PESSSOAS][NUMERO_MAXIMO_DE_PROBLEMAS],
        soma;

    while (scanf("%d %d", &numeroDeParticipantes, &numeroDeProblemas), numeroDeParticipantes != 0 || numeroDeProblemas != 0) {
        for (i = 0; i < numeroDeParticipantes; i++) {
            problemas[i][INDICE_DA_SOMA] = 0;
        }

        for (j = 0; j < numeroDeProblemas; j++) {
            problemas[INDICE_DA_SOMA][j] = 0;
        }

        for (i = 0; i < numeroDeParticipantes; i++) {
            for (j = 0; j < numeroDeProblemas; j++) {
                scanf("%d", &problemas[i][j]);

                problemas[i][INDICE_DA_SOMA] += problemas[i][j];
                problemas[INDICE_DA_SOMA][j] += problemas[i][j];
            }
        }

        soma = ninguemResolveuTodosOsProblemas(problemas, numeroDeParticipantes, numeroDeProblemas)
            + todoProblemaFoiResolvidoPorPeloMenosUmaPessoa(problemas, numeroDeParticipantes, numeroDeProblemas)
            + nenhumProblemaFoiResolvidoPorTodos(problemas, numeroDeParticipantes, numeroDeProblemas)
            + todosResolveramAoMenosUmProblema(problemas, numeroDeParticipantes, numeroDeProblemas);
        printf("%d\n", soma);
    }

    return 0;
}

int ninguemResolveuTodosOsProblemas(int problemas[][NUMERO_MAXIMO_DE_PROBLEMAS], int numeroDeParticipantes, int numeroDeProblemas) {
    int i,
        j,
        resolveuTodosOsProblemas;

    for (i = 0; i < numeroDeParticipantes; i++) {
        resolveuTodosOsProblemas = 1;

        for (j = 0; resolveuTodosOsProblemas && j < numeroDeProblemas; j++) {
            resolveuTodosOsProblemas = problemas[i][j] == 1;
        }

        if (resolveuTodosOsProblemas) {
            return 0;
        }
    }

    return 1;
}

int todoProblemaFoiResolvidoPorPeloMenosUmaPessoa(int problemas[][NUMERO_MAXIMO_DE_PROBLEMAS], int numeroDeParticipantes, int numeroDeProblemas) {
    int j,
        todoProblemaResolvidoPorPeloMenosUmaPessoa = 1;

    for (j = 0; todoProblemaResolvidoPorPeloMenosUmaPessoa && j < numeroDeProblemas; j++) {
        todoProblemaResolvidoPorPeloMenosUmaPessoa = problemas[INDICE_DA_SOMA][j] > 0;
    }

    if (todoProblemaResolvidoPorPeloMenosUmaPessoa) {
        return 1;
    }
    else {
        return 0;
    }
}

int nenhumProblemaFoiResolvidoPorTodos(int problemas[][NUMERO_MAXIMO_DE_PROBLEMAS], int numeroDeParticipantes, int numeroDeProblemas) {
    int j;

    for (j = 0; j < numeroDeProblemas; j++) {
        if (problemas[INDICE_DA_SOMA][j] == numeroDeParticipantes) {
            return 0;
        }
    }

    return 1;
}

int todosResolveramAoMenosUmProblema(int problemas[][NUMERO_MAXIMO_DE_PROBLEMAS], int numeroDeParticipantes, int numeroDeProblemas) {
    int i;

    for (i = 0; i < numeroDeParticipantes; i++) {
        if (problemas[i][INDICE_DA_SOMA] == 0) {
            return 0;
        }
    }

    return 1;
}
