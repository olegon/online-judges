/*
Flores Florescem da França
https://www.urionlinejudge.com.br/judge/pt/problems/view/1140
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1024

int palavrasComecamPelaMesmaLetra(const char *linha);

int main (void) {
    char linha[MAX_LENGTH];

    while (fgets(linha, MAX_LENGTH, stdin), strcmp(linha, "*\n") != 0) {
        if (palavrasComecamPelaMesmaLetra(linha)) {
            printf("Y\n");
        }
        else {
            printf("N\n");
        }
    }

    return 0;
}

int palavrasComecamPelaMesmaLetra(const char *linha) {
    int i = 0;
    int novaPalavra = 0;
    char primeiroCaractere;

    primeiroCaractere = toupper(linha[i]);

    while (linha[i] != '\0') {
        if (novaPalavra) {
            if (toupper(linha[i]) != primeiroCaractere) {
                return 0;
            }
            novaPalavra = 0;
        }
        else if (linha[i] == ' ') {
            novaPalavra = 1;
        }

        i++;
    }

    return 1;
}
