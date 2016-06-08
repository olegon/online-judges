#include <stdio.h>

int main (void) {
    int n,
        i;

    scanf("%d", &n);

    if (n > 2) {
        for (i = 2; i < 10000; i += n) {
            printf("%d\n", i);
        }
    }

    return 0;
}
