#include <stdio.h>
#include <stdlib.h>

typedef int STACK_TYPE;

typedef struct {
    STACK_TYPE *values;
    int indice;
    int size;
} STACK;

STACK* stack(int size);
void reset(STACK *stack);
void push(STACK *stack, STACK_TYPE dado);
STACK_TYPE pop(STACK *stack);
STACK_TYPE peek(const STACK *stack);
int size(const STACK *stack);
int empty(const STACK *stack);

#define STACK_SIZE 1024

int main (void) {

    return 0;
}

STACK* stack(int size) {
    STACK *stack;

    stack = malloc(sizeof(STACK));

    if (stack == NULL) {
        fprintf(stderr, "Sem espaço na memória.\n");
        exit(EXIT_FAILURE);
    }

    stack->values = malloc(sizeof(STACK_TYPE) * size);
    if (stack->values == NULL) {
        fprintf(stderr, "Sem espaço na memória.\n");
        exit(EXIT_FAILURE);
    }

    stack->indice = 0;
    stack->size = size;

    return stack;
}

void reset(STACK *stack) {
    stack->indice = 0;
}

void push(STACK *stack, STACK_TYPE dado) {
    stack->values[stack->indice++] = dado;
}

STACK_TYPE pop(STACK *stack) {
    return stack->values[--stack->indice];
}

STACK_TYPE peek(const STACK *stack) {
    return stack->values[stack->indice - 1];
}

int size(const STACK *stack) {
    return stack->indice;
}

int empty(const STACK *stack) {
    return size(stack) == 0;
}
