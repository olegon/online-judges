/*
Despojados
https://www.urionlinejudge.com.br/judge/pt/problems/view/2661
*/

#include <bits/stdc++.h>

#define DEBUG(N) cout << #N << " = " << N << endl;

using namespace std;

typedef unsigned long long int uint64;

vector<uint64> primosAte(uint64 n);
bool despojado(uint64 n, vector<uint64> &primos);

int main(void) {
    ios::sync_with_stdio(false);

    uint64 N, r = 0;

    cin >> N;

    vector<uint64> primos = primosAte(N);
    uint64 limit = sqrt(N);
    
    if (despojado(N, primos)) r++;
    for (uint64 i = 2; i <= limit; i++) {
        if (N % i == 0) {
            uint64 a = i, b = N / i;

            if (despojado(a, primos)) r++;
            if (b != a && despojado(b, primos)) r++;
        }
    }

    cout << r << endl;
    
    return EXIT_SUCCESS;
}

vector<uint64> primosAte(uint64 n) {
    vector<uint64> primos;

    if (n < 2) return primos;

    primos.push_back(2);
    
    uint64 limit = sqrt(n);
    for (uint64 i = 3; i <= limit; i += 2) {
        bool _primo = true;
        uint64 _limit = sqrt(i);

        for (uint64 p : primos) {
            if (!_primo || p > _limit) break;
            
            _primo = i % p != 0;
        }
        
        if (_primo) primos.push_back(i);
    }

    return primos;
}

bool despojado(uint64 n, vector<uint64> &primos) {
    uint64 ultimoDivisor = 0, divisores = 0;
    
    for (auto p = primos.begin(); n > 1 && p != primos.end(); ++p) {
        while (n % *p == 0) {
            if (ultimoDivisor == *p) return false;

            n /= *p;
            ultimoDivisor = *p;
            divisores++;
        }
    }

    return divisores > 1;
}
