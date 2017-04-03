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

            largada[i] = carro;
        }

        for (int i = 0; i < N; i++) {
            int carro;

            cin >> carro;

            chegada[i] = carro;
        }

        // N = 24, então KISS!
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (largada[j] == -1) continue;
                else if (largada[j] == chegada[i]) {
                    largada[j] = -1;
                    break;
                }
                else ultrapassagens++;
            }
        }

        cout << ultrapassagens << '\n';
    }

    return EXIT_SUCCESS;
}
