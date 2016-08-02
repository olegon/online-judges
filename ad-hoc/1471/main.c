#include <stdio.h>

#define QUANTIDADE_MERGULHADORES 10001

int main (void) {
    int foram, voltaram,
        mergulhadoresQueVoltaram[QUANTIDADE_MERGULHADORES],
        i,
        mergulhadorQueVoltou;

    for (i = 0; i < QUANTIDADE_MERGULHADORES; i++) {
        mergulhadoresQueVoltaram[i] = 0;
    }

    while (scanf("%d %d", &foram, &voltaram) == 2) {
        if (foram == voltaram) {
            // clear
            for (i = 1; i <= voltaram; i++) { scanf("%d", &mergulhadorQueVoltou); }

            printf("*");
        }
        else {
            for (i = 1; i <= voltaram; i++) {
                scanf("%d", &mergulhadorQueVoltou);

                // set
                mergulhadoresQueVoltaram[mergulhadorQueVoltou] = 1;
            }

            for (i = 1; i <= foram; i++) {
                if (!mergulhadoresQueVoltaram[i]) {
                    printf("%d ", i);
                }

                // reset
                mergulhadoresQueVoltaram[i] = 0;
            }
        }

        printf("\n");
    }

    return 0;
}
