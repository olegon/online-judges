#include <stdio.h>
#include <string.h>

#define STRING_SIZE 256

int main (void) {
    int     casos;
    char    nome[STRING_SIZE];

    scanf("%d\n", &casos);

    while (casos-- > 0) {
        scanf("%s %*d\n", nome);

        if (strcmp(nome, "Thor") == 0) {
            printf("Y\n");
        }
        else {
            printf("N\n");
        }
    }

    return 0;
}
