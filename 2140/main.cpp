/*
Duas Notas
https://www.urionlinejudge.com.br/judge/pt/problems/view/2140
*/

#include <iostream>
#include <vector>

using namespace std;

bool trocoPossivel(int N, int M);

int main(void) {
    ios::sync_with_stdio(false);

    int N, M;

    while (cin >> N >> M, N != 0 || M != 0) {
        if (trocoPossivel(N, M)) cout << "possible\n";
        else cout << "impossible\n";
    }

    return 0;
}

bool trocoPossivel(int N, int M) {
    vector<int> notas;

    notas.push_back(2);
    notas.push_back(5);
    notas.push_back(10);
    notas.push_back(20);
    notas.push_back(50);
    notas.push_back(100);

    int troco = M - N;

    for (size_t i = 0; i < notas.size(); i++) {
        for (size_t j = 0; j < notas.size(); j++) {
            if (notas[i] + notas[j] == troco) return true;
        }
    }

    return false;
}
