/*
Despojados
https://www.urionlinejudge.com.br/judge/pt/problems/view/2661
*/

#include <bits/stdc++.h>

#define DEBUG(N) cout << #N << " = " << N << endl;

using namespace std;

typedef unsigned long long int uint64;

bool despojado(uint64 n);
bool primo(uint64 n);

int main(void) {
    ios::sync_with_stdio(false);

    uint64 N, r = 0;

    cin >> N;

    if (primo(N)) {
        cout << 0 << endl;
    }
    else {
        uint64 limit = sqrt(N);
        
        if (despojado(N)) r++;
        for (uint64 i = 2; i <= limit; i++) {
            if (N % i == 0) {
                uint64 a = i, b = N / i;
    
                if (despojado(a)) r++;
                if (b != a && despojado(b)) r++;
            }
        }
    
        cout << r << endl;
    }
    
    return EXIT_SUCCESS;
}

bool primo(uint64 n) {
    if (n < 2) return false;
    if (n % 2 == 0) return false;

    uint64 limit = sqrt(n);

    for (uint64 i = 3; i <= limit; i += 2) {
        if (n % i == 0) return false;
    }

    return true;
}

bool despojado(uint64 n) {
    uint64 ultimoDivisor = 0, divisores = 0;
    
    while (n % 2 == 0) {
        if (ultimoDivisor == 2) return false;
        
        n /= 2;
        divisores++;
        ultimoDivisor = 2;
    }
    
    for (uint64 i = 3;  n != 1; i += 2) {
        while (n % i == 0) {
            if (ultimoDivisor == i) return false;

            n /= i;
            divisores++;
            ultimoDivisor = i;
        }
    }

    return divisores > 1;
}
