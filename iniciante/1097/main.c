#include <stdio.h>

int main (void) {
    int i,
        j;

    for (i = 1; i < 10; i += 2) {
        for (j = 7; j > 4; j--) {
            printf("I=%d J=%d\n", i, j + i - 1);
        }
    }


    return 0;
}
