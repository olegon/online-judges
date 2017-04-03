/*
Sort! Sort!! e Sort!!!
https://www.urionlinejudge.com.br/judge/pt/problems/view/1252
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N, M;

    while (cin >> N >> M, true) {
        cout << N << " " << M << endl;

        if (M == 0) break;
        
        vector<int> valores(N);

        for (int i = 0; i < N; i++) cin >> valores[i];

        sort(valores.begin(), valores.end(), [M] (int a, int b) -> bool {
            int ma = a % M;
            int mb = b % M;

            if (ma == mb) {
                bool aPar = a % 2 == 0;
                bool bPar = b % 2 == 0;

                if (aPar && bPar) return a < b;
                else if (!aPar && !bPar) return a > b;
                else if (aPar) return false;
                else return true;
            }
            else return ma < mb;
        });

        for (int valor : valores) cout << valor << endl;
    }

    return EXIT_SUCCESS;
}
