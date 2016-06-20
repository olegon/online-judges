#include <stdio.h>

void imprimirRegiao(int x, int y);

int main (void) {
    int casos,
        x0, y0,
        x1, y1;

    while (scanf("%d", &casos), casos != 0) {
        scanf("%d %d", &x0, &y0);

        while (casos-- > 0) {
            scanf("%d %d\n", &x1, &y1);

            imprimirRegiao(x1 - x0, y1 - y0);
        }
    }

    return 0;
}

void imprimirRegiao(int x, int y) {
    if (x == 0 || y == 0) {
        printf("divisa\n");
    }
    else {
        if (x > 0) {
            if (y > 0) {
                printf("NE\n");
            }
            else {
                printf("SE\n");
            }
        }
        else {
            if (y > 0) {
                printf("NO\n");
            }
            else {
                printf("SO\n");
            }
        }
    }
}
