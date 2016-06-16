#include <stdio.h>

#define maiuscula(c) ((c) >= 'A' && (c) <= 'Z')
#define minuscula(c) ((c) >= 'a' && (c) <= 'z')

int main (void) {
    int casos,
        a,
        b;

    char op;

    scanf("%d\n", &casos);

    while (casos-- > 0) {
        scanf("%d%c%d\n", &a, &op, &b);

        if (a == b) {
            printf("%d\n", a * b);
        }
        else if (maiuscula(op)) {
            printf("%d\n", b - a);
        }
        else {
            printf("%d\n", a + b);
        }
    }

    return 0;
}
