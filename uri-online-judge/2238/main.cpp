/*
Divisores
https://www.urionlinejudge.com.br/judge/pt/problems/view/2238
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int divisor, naoDivisor,
        multiplo, naoMultiplo,
        n = -1;

    vector<int> divisores;

    cin >> divisor >> naoDivisor >> multiplo >> naoMultiplo;

    /*

    Se (i) é um divisor de (múltiplo), então (múltiplo / i) também seu um divisor.
    Só é necessário testar até a (raiz de múltiplo), pois ((múltiplo) / (raiz do múltiplo)) é igual ao próprio múltiplo. Depois desse limite, os elementos do vetor passam a se repetir.

    */

    int raizDoMultiplo = sqrt(multiplo);

    for (int i = 1; i <= raizDoMultiplo; i++) {
        if (multiplo % i == 0) {
            divisores.push_back(i);
            divisores.push_back(multiplo / i);
        }
    }

    sort(divisores.begin(), divisores.end());

    for (size_t i = 0; i < divisores.size(); i++) {
        if (divisores[i] % divisor == 0 && divisores[i] % naoDivisor != 0 && naoMultiplo % divisores[i] != 0) {
            n = divisores[i];
            break;
        }
    }

    cout << n << endl;

    return EXIT_SUCCESS;
}
