#include <stdio.h>
#include <string.h>

#define TO_UPPER(c) ((c) >= 'a' && (c) <= 'z' ? (c) - 0x20 : (c))

void analisarPalavra(const char *palavra);
int caracteresIguais(const char *palavra, const char *str);

#define STRING_SIZE 32



int main (void) {
    int     casos;
    char    palavra[STRING_SIZE];

    scanf("%d\n", &casos);

    while (casos-- > 0) {
        scanf("%s\n", palavra);
        analisarPalavra(palavra);
    }

    return 0;
}

void analisarPalavra(const char *palavra) {
    if (caracteresIguais(palavra, "one") >= 2) {
        printf("1\n");
    }
    else if (caracteresIguais(palavra, "two") >= 2) {
        printf("2\n");
    }
    else if (caracteresIguais(palavra, "three") >= 4) {
        printf("3\n");
    }
}

int caracteresIguais(const char *palavra, const char *str) {
    int i = 0,
        quantidadeDeCaracteresIguais = 0;

    while (palavra[i] != '\0' && str[i] != '\0') {
        if (TO_UPPER(palavra[i]) == TO_UPPER(str[i])) {
            quantidadeDeCaracteresIguais++;
        }

        i++;
    }

    return quantidadeDeCaracteresIguais;
}
