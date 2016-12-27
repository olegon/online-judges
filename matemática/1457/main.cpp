/*
Oráculo de Alexandria
https://www.urionlinejudge.com.br/judge/pt/problems/view/1457
*/

#include <cstdio>

using namespace std;

typedef unsigned long long int uint64;

uint64 k_fat(int N, int K);

int main(void) {
    int T;

    scanf("%d\n", &T);

    while (T-- > 0) {
        int N, K = 0;
        char C;

        scanf("%d", &N);

        while (scanf("%c", &C), C == '!') K++;

        printf("%llu\n", k_fat(N, K));
    }

    return 0;
}

uint64 k_fat(int N, int K) {
    if (N < 2) return 1;
    else return N * k_fat(N - K, K);
}
