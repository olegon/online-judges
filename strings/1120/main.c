#include <stdio.h>
#include <string.h>

#define STRING_SIZE 128

int main (void) {
    char    tecla,
            contrato[STRING_SIZE],
            *str;

    while (scanf("%c %s\n", &tecla, contrato), tecla != '0' || strcmp(contrato, "0") != 0) {
        // Eliminar caracteres com falha
        str = contrato;
        while (str = strchr(str, tecla), str != NULL) {
            strcpy(str, str + 1);
        }

        // Eliminar zeros à esquerda
        str = contrato;
        while (str[0] == '0') {
            strcpy(str, str + 1);
        }

        // Se não sobrou nada, então é 0.
        if (contrato[0] == '\0') {
            printf("0\n");
        }
        else {
            printf("%s\n", contrato);
        }
    }

    return 0;
}
