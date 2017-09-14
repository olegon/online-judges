/*
Triângulo de Pascal
https://www.urionlinejudge.com.br/judge/pt/problems/view/2232
*/

#include <iostream>

using namespace std;

typedef long long unsigned int uint64;

uint64 pow(uint64 base, uint64 exp);

int main(void) {
    ios::sync_with_stdio(false);

    int T;

    cin >> T;

    while (T-- > 0) {
      int N;

      cin >> N;

      cout << pow(2, N) - 1 << '\n';
    }

    return 0;
}

uint64 pow(uint64 base, uint64 exp) {
  if (exp == 0) return 1;

  uint64 v = pow(base, exp / 2);

  if (exp % 2 == 0) return v * v;
  else              return v * v * base;
}
