#include <stdio.h>

int main (void) {
    int x,
        y;

    while (scanf("%d %d\n", &x, &y), x != y) {
        if (x < y) {
            printf("Crescente\n");
        }
        else {
            printf("Decrescente\n");
        }
    }

    return 0;
}
