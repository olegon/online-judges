#include <stdio.h>
#include <stdlib.h>

typedef int TIPO_DA_PILHA;

typedef struct {
    TIPO_DA_PILHA *valores;
    int indice;
} PILHA;

PILHA* pilha_criar(int tamanho);
void pilha_reset(PILHA *pilha);
void pilha_push(PILHA *pilha, TIPO_DA_PILHA dado);
TIPO_DA_PILHA pilha_pop(PILHA *pilha);

#define PILHA_SIZE 1024

int main (void) {
    int vagoes;

    return 0;
}

PILHA* pilha_criar(int tamanho) {
    PILHA *pilha;

    pilha = malloc(sizeof(PILHA));

    if (pilha == NULL) {
        fprintf(stderr, "Sem espaço na memória.\n");
        exit(EXIT_FAILURE);
    }

    pilha->valores = malloc(sizeof(TIPO_DA_PILHA) * tamanho);
    if (pilha->valores == NULL) {
        fprintf(stderr, "Sem espaço na memória.\n");
        exit(EXIT_FAILURE);
    }

    pilha->indice = 0;

    return pilha;
}

void pilha_reset(PILHA *pilha) {
    pilha->indice = 0;
}

void pilha_push(PILHA *pilha, TIPO_DA_PILHA dado) {
    pilha->valores[pilha->indice++] = dado;
}

TIPO_DA_PILHA pilha_pop(PILHA *pilha) {
    return pilha->valores[--pilha->indice];
}
