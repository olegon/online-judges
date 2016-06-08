#include <stdio.h>

int main (void) {
    double  s,
            t = 0;

    for (s = 1; s <= 100.0; s++) {
        t += 1 / s;
    }

    printf("%.2f\n", t);

    return 0;
}
