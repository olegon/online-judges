#include <iostream>

using namespace std;

#define MAX_NUM 17

unsigned long long int sequencia[MAX_NUM + 1];

int main(void) {
    ios::sync_with_stdio(false);

    sequencia[1] = 0;
    sequencia[2] = 1;

    // DP
    for (int i = 3; i <= MAX_NUM; i++) {
        if (i % 2 == 0) sequencia[i] = sequencia[i - 2] * sequencia[i - 1];
        else sequencia[i] = sequencia[i - 2] + sequencia[i - 1];
    }

    int N;

    while (cin >> N) {
        cout << sequencia[N] << '\n';
    }

    return 0;
}
