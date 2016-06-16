#include <stdio.h>

#define isUppercase(c) ((c) >= 'A' && (c) <= 'Z')
#define isLowercase(c) ((c) >= 'a' && (c) <= 'z')
#define ehLetra(c) (isUppercase(c) || isLowercase(c))
#define uppercase(c) (isLowercase(c) ? (c) - 0x20 : (c))
#define lowercase(c) (isUppercase(c) ? (c) + 0x20 : (c))

int main (void) {
    int caractere,
        ultimaFoiMaiuscula = 0;

    while (caractere = getc(stdin), caractere != EOF) {
        if (ehLetra(caractere)) {
            if (ultimaFoiMaiuscula) {
                putc(lowercase(caractere), stdout);
            }
            else {
                putc(uppercase(caractere), stdout);
            }

            ultimaFoiMaiuscula = !ultimaFoiMaiuscula;
        }
        else {
            putc(caractere, stdout);
        }

        if (caractere == '\n') {
            ultimaFoiMaiuscula = 0;
        }
    }

    return 0;
}
