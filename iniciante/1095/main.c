#include <stdio.h>

int main (void) {
    int i = 1,
        j = 60;

    while (j > -5) {
        printf("I=%d J=%d\n", i, j);

        i += 3;
        j -= 5;
    }

    return 0;
}
