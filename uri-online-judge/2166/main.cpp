/*
Raiz Quadrada de 2
https://www.urionlinejudge.com.br/judge/pt/problems/view/2166
*/

#include <iostream>
#include <iomanip>

double sqrt2 (int n);
double divisoesAninhadas (int a, int b, int n);

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    cout << fixed << setprecision(10) << sqrt2(N) << endl;

    return 0;
}

double sqrt2 (int n) {
  if (n == 0) return 1.0;
  else return 1.0 + 1.0 / divisoesAninhadas(1, 2, n);
}

double divisoesAninhadas (int a, int b, int n) {
  if (n == 1) return b;
  else return b + a / divisoesAninhadas(a, b, n - 1);
}
