#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 2048

void identarPrograma(const char *codigo);
void imprimirIdentacao(int nivel);

int main (void) {
    char codigo[MAX_LENGTH];

    while (fgets(codigo, MAX_LENGTH, stdin) != NULL) {
        identarPrograma(codigo);
    }

    return 0;
}

void identarPrograma(const char *codigo) {
    int i = 0;
    int nivelIdentacao = 0;
    int novaLinha = 0;

    while (codigo[i] != '\0') {
        char caractere = codigo[i++];

        if (novaLinha) {
            // if (caractere == ' ') {
            //     continue;
            // }
            if (caractere == '}') {
                putchar('\n');
                imprimirIdentacao(--nivelIdentacao);
            }
            else {
                printf("\n");
                imprimirIdentacao(nivelIdentacao);
                novaLinha = 0;
            }
        }

        if (caractere == '{') {
            putchar('\n');
            imprimirIdentacao(nivelIdentacao++);
            printf("{");
            novaLinha = 1;
        }
        else if (caractere == ';') {
            printf(";");
            novaLinha = 1;
        }
        else if (strncmp("for", codigo + i - 1, 3) == 0) {
            while (caractere != '{') {
                putchar(caractere);
                caractere = codigo[i++];
            }
            i--;
        }
        // else if (strncmp("#define", codigo + i - 1, 7) == 0) {
        //     int espacos = 0;
        //     while (espacos != 3) {
        //         if (caractere == ' ') {
        //             espacos++;
        //         }
        //
        //         putchar(caractere);
        //         caractere = codigo[i++];
        //     }
        //     i--;
        //     novaLinha = 1;
        // }
        // else if (strncmp("#include", codigo + i - 1, 8) == 0) {
        //     int espacos = 0;
        //     while (espacos != 2) {
        //         if (caractere == ' ') {
        //             espacos++;
        //         }
        //
        //         putchar(caractere);
        //         caractere = codigo[i++];
        //     }
        //     i--;
        //     novaLinha = 1;
        // }
        else {
            putchar(caractere);
        }
    }
}

void imprimirIdentacao(int nivel) {
    while (nivel-- > 0) {
        printf("....");
    }
}
