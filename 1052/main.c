/*
Mês
https://www.urionlinejudge.com.br/judge/pt/problems/view/1052
*/

#include <stdio.h>

int main (void) {
    const char *meses[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

    int mes;

    scanf("%d", &mes);

    if (mes < 13) {
        printf("%s\n", meses[mes - 1]);
    }
    else {
        printf("Unknown\n");
    }


    return 0;
}
