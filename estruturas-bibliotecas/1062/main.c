#include <stdio.h>
#include <stdlib.h>

typedef int STACK_TYPE;

typedef struct {
    STACK_TYPE *values;
    int indice;
    int size;
} *STACK;

STACK stack(int size);
void reset(STACK stack);
void push(STACK stack, STACK_TYPE dado);
STACK_TYPE pop(STACK stack);
STACK_TYPE peek(const STACK stack);
int size(const STACK stack);
int empty(const STACK stack);

#define STACK_SIZE 1024

int main (void) {
    int quantidadeDeVagoes,
        vagaoQueEstaEntrando,
        vagaoQueDeveSair;

    STACK vagoesQueEntraram;

    vagoesQueEntraram = stack(STACK_SIZE);

    while (scanf("%d", &quantidadeDeVagoes), quantidadeDeVagoes != 0) {

        while (scanf("%d", &vagaoQueDeveSair), vagaoQueDeveSair != 0) {
            reset(vagoesQueEntraram);
            vagaoQueEstaEntrando = 1;

            if (vagaoQueDeveSair != vagaoQueEstaEntrando) {
                push(vagoesQueEntraram, vagaoQueEstaEntrando);
            }

            for (vagaoQueEstaEntrando = 2; vagaoQueEstaEntrando <= quantidadeDeVagoes; vagaoQueEstaEntrando++) {
                scanf("%d", &vagaoQueDeveSair);

                if (vagaoQueDeveSair == vagaoQueEstaEntrando) {
                    continue;
                }
                else if (!empty(vagoesQueEntraram) && peek(vagoesQueEntraram) == vagaoQueDeveSair) {
                    pop(vagoesQueEntraram);
                }
                else {
                    push(vagoesQueEntraram, vagaoQueEstaEntrando);
                }
            }

            if (empty(vagoesQueEntraram)) {
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }
        }

        printf("\n");
    }


    return 0;
}

STACK stack(int size) {
    STACK stack;

    stack = malloc(sizeof(STACK));

    if (stack == NULL) {
        fprintf(stderr, "Sem espaço na memória.\n");
        abort();
    }

    stack->values = malloc(sizeof(STACK_TYPE) * size);
    if (stack->values == NULL) {
        fprintf(stderr, "Sem espaço na memória.\n");
        abort();
    }

    stack->indice = 0;
    stack->size = size;

    return stack;
}

void reset(STACK stack) {
    stack->indice = 0;
}

void push(STACK stack, STACK_TYPE dado) {
    stack->values[stack->indice++] = dado;
}

STACK_TYPE pop(STACK stack) {
    return stack->values[--stack->indice];
}

STACK_TYPE peek(const STACK stack) {
    return stack->values[stack->indice - 1];
}

int size(const STACK stack) {
    return stack->indice;
}

int empty(const STACK stack) {
    return size(stack) == 0;
}
