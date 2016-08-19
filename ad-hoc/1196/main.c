#include <stdio.h>

#define MAX_STRING_SIZE 1024

char sequence[] = {
    '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
    'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\',
    'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'',
    'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/',
    '\0'
};

char obterLetraCorreta(char caractere);

int main (void) {
    char    caractere;

    while (scanf("%c", &caractere) != EOF) {
        if (caractere == '\n') {
            printf("\n");
        }
        else {
            printf("%c", obterLetraCorreta(caractere));
        }
    }

    return 0;
}

char obterLetraCorreta(char caractere) {
    char *sequencePtr;

    if (caractere == ' ') {
        return ' ';
    }

    sequencePtr = sequence;

    while (*sequencePtr != '\0') {
        if (*sequencePtr == caractere) {
            return *(sequencePtr - 1);
        }

        sequencePtr++;
    }

    return '\0';
}
