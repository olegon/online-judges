#include <stdio.h>

int main (void) {
    int v, t;

    while (scanf("%d %d", &v, &t) != EOF) {
        printf("%d\n", v * t * 2);
    }

    return 0;
}
