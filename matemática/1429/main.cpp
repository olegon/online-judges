#include <iostream>

using namespace std;

typedef unsigned long long int uint64;

uint64 obter_decimal(int acm);

int fatorial[10];

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    fatorial[0] = 1;
    for (int i = 1; i <= 9; i++) {
        fatorial[i] = i * fatorial[i - 1];
    }

    while (cin >> N, N != 0) {
        cout << obter_decimal(N) << '\n';
    }

    return 0;
}

uint64 obter_decimal(int acm) {
    uint64 decimal = 0;

    for (int i = 1; acm != 0; i++) {
        decimal += (acm % 10) * fatorial[i];

        acm /= 10;
    }

    return decimal;
}
