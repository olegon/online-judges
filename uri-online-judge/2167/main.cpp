/*
Falha do Motor
https://www.urionlinejudge.com.br/judge/pt/problems/view/2167
*/

#include <iostream>
#include <vector>

using namespace std;

int obterPrimeiraQuedaDeValor(std::vector<int> &medidas);

int main(void) {
    ios::sync_with_stdio(false);

    int N;
    vector<int> medidas;

    cin >> N;

    for (int i = 0; i < N; i++) {
      int R;

      cin >> R;

      medidas.push_back(R);
    }

    cout << obterPrimeiraQuedaDeValor(medidas) << endl;

    return 0;
}

int obterPrimeiraQuedaDeValor(std::vector<int> &medidas) {
  for (size_t i = 1; i < medidas.size(); i++) {
    if (medidas[i] < medidas[i - 1]) return (i + 1);
  }

  return 0;
}
