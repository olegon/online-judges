/*
Balanço de Parênteses I
https://www.urionlinejudge.com.br/judge/pt/problems/view/1068
*/

#include <stdio.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int avaliarExpressao(char *str, int expressoesAbertas);

#define STRING_SIZE 1024

int main (void) {
    int casos;
    char str[STRING_SIZE];

    scanf("%d\n", &casos);

    while (fgets(str, STRING_SIZE, stdin) != NULL) {
        printf("%s\n", avaliarExpressao(str, 0) ? "correct" : "incorrect");
    }

    return 0;
}

int avaliarExpressao(char *str, int expressoesAbertas) {
    if (*str == '\n') {
        return expressoesAbertas == 0;
    }
    else if (*str == '(') {
        return avaliarExpressao(str + 1, expressoesAbertas + 1);
    }
    else if (*str == ')') {
        if (expressoesAbertas > 0) {
            return avaliarExpressao(str + 1, expressoesAbertas - 1);
        }
        else {
            return 0;
        }
    }
    else {
        return avaliarExpressao(str + 1, expressoesAbertas);
    }
}
