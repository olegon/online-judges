#include <cstdio>
#include <cstring>

using namespace std;

int main(void) {
    int N;

    scanf("%d\n", &N);

    while (N-- > 0) {
        int C,
            p = 0;

        scanf("%d\n", &C);

        int commands[C];

        for (int i = 0; i < C; i++) {
            char word[16];

            scanf("%s%*c", word);

            if (strcmp(word, "LEFT") == 0) {
                commands[i] = -1;
            }
            else if (strcmp(word, "RIGHT") == 0) {
                commands[i] = +1;
            }
            else {
                int S;

                scanf("AS %d\n", &S);

                commands[i] = commands[S - 1];
            }

            p += commands[i];
        }

        printf("%d\n", p);
    }

    return 0;
}
