#include <stdio.h>

int main (void) {
    int casos,
        quantidade;

    scanf("%d", &casos);

    while (casos-- > 0) {
        scanf("%d", &quantidade);

        if (quantidade % 2 != 0) {
            printf("1\n");
        }
        else {
            printf("0\n");
        }
    }

    return 0;
}
