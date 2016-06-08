#include <stdio.h>

int main (void) {
    int x, y;

    while (scanf("%d %d\n", &x, &y), x != 0 && y != 0) {
        if (x < 0) {
            if (y < 0) {
                printf("terceiro\n");
            }
            else {
                printf("segundo\n");
            }
        }
        else {
            if (y < 0) {
                printf("quarto\n");
            }
            else {
                printf("primeiro\n");
            }
        }
    }

    return 0;
}
