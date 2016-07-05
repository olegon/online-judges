#include <stdio.h>

#define STR_SIZE 64

int main (void) {
    char    numero[STR_SIZE];
    int     valor;

    while (scanf("%s\n", numero), numero[0] != '-') {
        if (numero[0] == '0' && numero[1] == 'x') {
            sscanf(numero, "%x", &valor);
            printf("%d\n", valor);
        }
        else {
            sscanf(numero, "%d", &valor);
            printf("0x%X\n", valor);
        }


    }

    return 0;
}
