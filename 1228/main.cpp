/*
Grid de Largada
https://www.urionlinejudge.com.br/judge/pt/problems/view/1228
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    while (cin >> N) {
        vector<int> largada(N);
        vector<int> chegada(N);
        int ultrapassagens = 0;

        for (int i = 0; i < N; i++) {
            int carro;

            cin >> carro;

            largada[carro - 1] = i;
        }

        for (int i = 0; i < N; i++) {
            int carro;

            cin >> carro;

            chegada[i] = carro;
        }

        for (int i = 1; i < N; i++) {
            int carroA = chegada[i - 1];
            int carroB = chegada[i];
            int diff = largada[carroA - 1] - largada[carroB - 1];

            ultrapassagens += max(0, diff);
        }

        cout << ultrapassagens << '\n';
    }

    return EXIT_SUCCESS;
}
