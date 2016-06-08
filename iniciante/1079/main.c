#include <stdio.h>

int main (void) {
    int     n;
    double  a,
            b,
            c;

    scanf("%d", &n);

    while (n-- > 0) {
        scanf("%lf %lf %lf", &a, &b, &c);
        printf("%.1f\n", a * 0.2 + b * 0.3 + c * 0.5);
    }

    return 0;
}
