/*
Prefácio
https://www.urionlinejudge.com.br/judge/pt/problems/view/1837
*/

#include <stdio.h>
#include <math.h>

int main (void) {
    int a,
        b,
        quociente,
        resto;

    scanf("%d %d", &a, &b);

    if (b > 0) {
        quociente = (int)floor((double)a / b);
    }
    else {
        quociente = (int)ceil((double)a / b);
    }

    resto = a - quociente * b;

    printf("%d %d\n", quociente, resto);


    return 0;
}
