#include <stdio.h>

#define MENOR 10
#define MANOR 20

int main (void) {
    int n,
        x,
        in = 0,
        out = 0;

    scanf("%d", &n);

    while (n-- > 0) {
        scanf("%d", &x);

        if (x < MENOR || x > MANOR) {
            out++;
        }
        else {
            in++;
        }
    }

    printf("%d in\n", in);
    printf("%d out\n", out);

    return 0;
}
