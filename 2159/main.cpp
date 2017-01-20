/*
Número Aproximado de Primo
https://www.urionlinejudge.com.br/judge/pt/problems/view/2159
*/

#include <iostream>
#include <utility>
#include <cmath>
#include <iomanip>

using namespace std;

pair<double, double> obterIntervalo(int n);

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    pair<double, double> intervalo = obterIntervalo(N);

    cout << fixed << setprecision(1) << intervalo.first << ' ' << intervalo.second << endl;

    return 0;
}

pair<double, double> obterIntervalo(int n) {
  double nDivLogN = 1.0 * n / log(n);

  return make_pair(nDivLogN, 1.25506 * nDivLogN);
}
