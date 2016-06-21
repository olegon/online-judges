#include <stdio.h>
#include <string.h>

#define STRING_SIZE 1024

int main (void) {
    int casos;

    char    a[STRING_SIZE],
            b[STRING_SIZE];

    scanf("%d\n", &casos);

    while (casos-- > 0) {
        scanf("%s %s\n", a, b);

        if (strcmp(a + strlen(a) - strlen(b), b) == 0) {
            printf("encaixa\n");
        }
        else {
            printf("nao encaixa\n");
        }
    }

    return 0;
}
