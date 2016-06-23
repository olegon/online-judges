#include <stdio.h>

#define MINUSCULA(c) ((c) >= 'a' && (c) <= 'z')
#define MAIUSCULA(c) ((c) >= 'A' && (c) <= 'Z')

#define TAMANHO_DA_LINHA 64

void imprimirCriptografado(const char *linha);

int main (void) {
    char    linha[TAMANHO_DA_LINHA];

    while(fgets(linha, TAMANHO_DA_LINHA, stdin) != NULL) {
        imprimirCriptografado(linha);
    }

    return 0;
}

void imprimirCriptografado(const char *linha) {
    char caractere;
    int i = 0;

    while (caractere = linha[i++], caractere != '\0') {
        if (MINUSCULA(caractere)) {
            caractere -= 13;

            if (caractere < 'a') {
                caractere = 'z' - ('a' - caractere) + 1;
            }
        }
        else if (MAIUSCULA(caractere)) {
            caractere -= 13;

            if (caractere < 'A') {
                caractere = 'Z' - ('A' - caractere) + 1;
            }
        }

        putc(caractere, stdout);
    }
}
