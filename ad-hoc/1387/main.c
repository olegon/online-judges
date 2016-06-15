#include <stdio.h>

int main (void) {
    int homens,
        mulheres;

    while (scanf("%d %d", &homens, &mulheres), homens != 0 || mulheres != 0) {
        printf("%d\n", homens + mulheres);
    }

    return 0;
}
