#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int uint64;

set<uint64> primos_distintos_da_fatoracao(uint64 n);

int main(void) {
    ios::sync_with_stdio(false);

    uint64 N, S;

    cin >> N;

    set<uint64> C = primos_distintos_da_fatoracao(N);
    
    S = pow(2, C.size()) - C.size() - 1;

    cout << S << endl;

    return EXIT_SUCCESS;
}

set<uint64> primos_distintos_da_fatoracao(uint64 n) {
    set<uint64> primos_distintos;

    while (n % 2 == 0) {
        primos_distintos.insert(2);
        n /= 2;
    }

    for (uint64 i = 3; n != 1 && i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            primos_distintos.insert(i);
            n /= i;
        }
    }

    if (n > 1) primos_distintos.insert(n);

    return primos_distintos;
}