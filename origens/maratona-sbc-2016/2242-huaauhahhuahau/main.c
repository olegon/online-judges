#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define EH_VOGAL(c) ((c) == 'a' || (c) == 'e' || (c) == 'i' || (c) == 'o' || (c) == 'u')
#define TAMANHO_MAXIMO 64

void copiarVogais(char *dest, const char *src);
int ehPalindroma(const char *palavra);

int main (void) {
    char    palavra[TAMANHO_MAXIMO],
            vogaisDaPalavra[TAMANHO_MAXIMO];

    scanf("%s", palavra);

    copiarVogais(vogaisDaPalavra, palavra);

    if (ehPalindroma(vogaisDaPalavra)) {
        printf("S\n");
    }
    else {
        printf("N\n");
    }

    return 0;
}

void copiarVogais(char *dest, const char *src) {
    while (*src != '\0') {
        if (EH_VOGAL(*src)) {
            *dest = *src;
            dest++;
        }

        src++;
    }

    *dest = '\0';
}

int ehPalindroma(const char *palavra) {
    int length,
        i;

    length = strlen(palavra);

    for (i = 0; i < length / 2; i++) {
        if (palavra[i] != palavra[length - i - 1]) {
            return 0;
        }
    }

    return 1;
}
