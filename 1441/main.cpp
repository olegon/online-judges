/*
Sequências de Granizo
https://www.urionlinejudge.com.br/judge/pt/problems/view/1441
*/

#include <iostream>

using namespace std;

int go(int n);

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    while (cin >> N, N != 0) {
      int resultado = go(N);

      cout << resultado << '\n';
    }

    return 0;
}

int go(int n) {
  int maximum = n;

  while (n != 1) {
    if (n % 2 == 0) {
       n = n / 2;
    }
    else {
      n = 3 * n + 1;
      maximum = max(n, maximum);
    }
  }

  return maximum;
}
