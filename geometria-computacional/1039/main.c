#include <stdio.h>
#include <math.h>

#define ABS(n) ((n) < 0 ? -(n) : (n))
// WA: 10%

int consegue(int r1, int x1, int y1, int r2, int x2, int y2);

int main (void) {
    int r1, x1, y1,
        r2, x2, y2;

    while (scanf("%d %d %d %d %d %d\n", &r1, &x1, &y1, &r2, &x2, &y2) != EOF) {
        if (consegue(r1, x1, y1, r2, x2, y2)) {
            printf("RICO\n");
        }
        else {
            printf("MORTO\n");
        }
    }

    return 0;
}

int consegue(int r1, int x1, int y1, int r2, int x2, int y2) {
    double hip;

    hip = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    return r1 >= r2 + hip;
}
