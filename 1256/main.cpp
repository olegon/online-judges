/*
Tabelas Hash
https://www.urionlinejudge.com.br/judge/pt/problems/view/1256
*/

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    while (N-- > 0) {
        int M, C;

        cin >> M >> C;

        vector<int> table[M];

        while (C-- > 0) {
            int X;

            cin >> X;

            table[X % M].push_back(X);
        }

        for (int i = 0; i < M; i++) {
            cout << i << " -> ";

            for (size_t j = 0; j < table[i].size(); j++) {
                cout << table[i][j] << " -> ";
            }

            cout << "\\\n";
        }

        if (N > 0) cout << '\n';
    }

    return 0;
}
