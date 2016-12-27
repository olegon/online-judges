/*
Jogando Cartas Fora
https://www.urionlinejudge.com.br/judge/pt/problems/view/1110
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} NO;

typedef struct fifo {
    struct no *cabeca;
    struct no *rabo;
    int size;
} FIFO;

void adicionar(FIFO *fifo, int valor);
int remover(FIFO *fifo);

FIFO* criar(void);
void apagar(FIFO *fifo);

void preencherBaralho(FIFO *baralho, int quantidade);

int main (void) {
    FIFO *baralho;
    int quantidade;
    int primeira, segunda;

    baralho = criar();

    while (scanf("%d", &quantidade), quantidade != 0) {
        preencherBaralho(baralho, quantidade);

        printf("Discarded cards: ");

        while (baralho->size > 2) {
            primeira = remover(baralho);
            segunda = remover(baralho);

            adicionar(baralho, segunda);

            printf("%d, ", primeira);
        }

        printf("%d\n", remover(baralho));
        printf("Remaining card: %d\n", remover(baralho));
    }

    apagar(baralho);

    return 0;
}

void adicionar(FIFO *fifo, int valor) {
    NO *no;

    no = malloc(sizeof(NO));
    no->valor = valor;
    no->proximo = NULL;

    fifo->size++;

    if (fifo->rabo == NULL) {
        fifo->cabeca = fifo->rabo = no;
    }
    else {
        fifo->rabo->proximo = no;
        fifo->rabo = no;
    }
}

int remover(FIFO *fifo) {
    NO *no;
    int valor;

    fifo->size--;

    no = fifo->cabeca;
    valor = no->valor;

    fifo->cabeca = fifo->cabeca->proximo;
    if (fifo->cabeca == NULL) {
        fifo->rabo = NULL;
    }

    free(no);

    return valor;
}

FIFO* criar(void) {
    FIFO *fifo;

    fifo = malloc(sizeof(FIFO));
    fifo->cabeca = fifo->rabo = NULL;
    fifo->size = 0;

    return fifo;
}

void apagar(FIFO *fifo) {
    while (fifo->cabeca != NULL) {
        remover(fifo);
    }

    free(fifo);
}

void preencherBaralho(FIFO *baralho, int quantidade) {
    int i;

    for (i = 1; i <= quantidade; i++) {
        adicionar(baralho, i);
    }
}
