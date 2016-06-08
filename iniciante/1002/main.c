#include <stdio.h>

int main (void) {
    double r;
    double pi = 3.14159;

    scanf("%lf", &r);
    printf("A=%.4lf\n", r * r * pi);

    return 0;
}
