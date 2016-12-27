/*
Soma de Dois Quadrados
https://www.urionlinejudge.com.br/judge/pt/problems/view/1558
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define QUANTIDADE_QUADRADOS 100

int quadrados[QUANTIDADE_QUADRADOS + 1];

int main(void) {
    ios::sync_with_stdio(false);
    vector<int> possiveis;

    for (int i = 0; i <= QUANTIDADE_QUADRADOS; i++) {
        quadrados[i] = i * i;
    }

    for (int i = 0; i <= QUANTIDADE_QUADRADOS; i++) {
        for (int j = 0; j <= QUANTIDADE_QUADRADOS; j++) {
            possiveis.push_back(quadrados[i] + quadrados[j]);
        }
    }

    sort(possiveis.begin(), possiveis.end());

    int N;
    while (cin >> N) {
        if (binary_search(possiveis.begin(), possiveis.end(), N)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
