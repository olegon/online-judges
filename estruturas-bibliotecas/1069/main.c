#include <stdio.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int extrairDiamantes(char *str, int half, int found);

#define STRING_SIZE 1024

int main (void) {
    int casos;
    char str[STRING_SIZE];

    scanf("%d\n", &casos);

    while (casos-- > 0) {
        scanf("%s\n", str);
        printf("%d\n", extrairDiamantes(str, 0, 0));
    }

    return 0;
}

int extrairDiamantes(char *str, int half, int found) {
    if (*str == '\0') {
        return found;
    }
    else if (*str == '<') {
        return extrairDiamantes(str + 1, half + 1, found);
    }
    else if (*str == '>') {
        if (half > 0) {
            return extrairDiamantes(str + 1, half - 1, found + 1);
        }
        else {
            return extrairDiamantes(str + 1, half, found);
        }
    }
    else {
        return extrairDiamantes(str + 1, half, found);
    }
}
