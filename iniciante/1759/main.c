#include <stdio.h>

int main (void) {
    int n;

    scanf("%d", &n);

    while (n-- > 0) {
        printf("Ho");

        if (n == 0) {
            printf("!\n");
        }
        else {
            printf(" ");
        }
    }

    return 0;
}
