/*
Cigarras
https://www.urionlinejudge.com.br/judge/pt/problems/view/2660
*/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int uint64;

uint64 mdc(uint64 a, uint64 b) {
    if (a == 0) return b;
    else return mdc(b % a, a);
}

uint64 mmc(uint64 a, uint64 b) {
    return a / mdc(a, b) * b;
}

int main(void) {
    ios::sync_with_stdio(false);

    uint64 N, L,
        cicloAtual = 1,
        melhorCiclo,
        tempoDeVida = 1;

    cin >> N >> L;

    for (uint64 i = 0; i < N; i++) {
        uint64 n;
        cin >> n;
        cicloAtual = mmc(cicloAtual, n);
    }

    melhorCiclo = cicloAtual;

    for (uint64 i = 1; i <= L; i++) {
        uint64 ciclo = mmc(cicloAtual, i);

        if (ciclo > melhorCiclo && ciclo <= L) {
            melhorCiclo = ciclo;
            tempoDeVida = i;
        }
    }

    cout << tempoDeVida << endl;

    return EXIT_SUCCESS;
}
