#include <stdio.h>

int main (void) {
    int jogadas,
        jogo,
        mary,
        john;

    while (scanf("%d", &jogadas), jogadas != 0) {
        mary = john = 0;
        
        while (jogadas-- > 0) {
            scanf("%d", &jogo);

            if (jogo == 0) {
                mary++;
            }
            else {
                john++;
            }
        }

        printf("Mary won %d times and John won %d times\n", mary, john);
    }

    return 0;
}
