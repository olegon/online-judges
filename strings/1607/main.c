#include <stdio.h>

#define MAX_LENGTH 10001

int calcularOperacoes(const char *sa, const char *sb);

int main (void) {
    int     casos;

    char    sa[MAX_LENGTH],
            sb[MAX_LENGTH];

    scanf("%d", &casos);

    while (casos-- > 0) {
        scanf("%s %s\n", sa, sb);
        printf("%d\n", calcularOperacoes(sa, sb));
    };

    return 0;
}

int calcularOperacoes(const char *sa, const char *sb) {
    int operacoes = 0;

    while (*sa != '\0') {
        if (*sa < *sb) {
            operacoes += *sb - *sa;
        }
        else if (*sa > *sb)  {
            operacoes += 'z' - *sa + *sb - 'a' + 1;
        }

        sa++;
        sb++;
    }

    return operacoes;
}
