/*
Evento
https://www.urionlinejudge.com.br/judge/pt/problems/view/2172
*/

#include <iostream>

typedef unsigned long long int uint64;

uint64 calcular(uint64 x, uint64 y);

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    uint64 X, M;

    while (cin >> X >> M, X != 0 || M != 0) {
      cout << calcular(X, M) << endl;
    }

    return 0;
}

uint64 calcular(uint64 x, uint64 y) {
  return x * y;
}
