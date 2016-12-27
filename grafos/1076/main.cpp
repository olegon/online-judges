/*
Desenhando Labirintos
https://www.urionlinejudge.com.br/judge/pt/problems/view/1076
*/

#include <iostream>

#define MAX_N 49

using namespace std;

void reset(bool mat[MAX_N][MAX_N]);
int get_i(int n, int V);
int get_j(int n, int V);

int main(void) {
    ios::sync_with_stdio(false);

    int T;

    cin >> T;

    while (T-- > 0) {
        int N;

        cin >> N;

        int V, A;

        cin >> V >> A;

        bool mat[MAX_N][MAX_N];
        reset(mat);

        int count = 0;

        for (int i = 0; i < A; i++) {
            int a, b;

            cin >> a >> b;

            if (mat[b][a] || mat[a][b]) continue;

            mat[a][b] = true;
            count++;
        }

        cout << (2 * count) << '\n';
    }

    return 0;
}

void reset(bool mat[MAX_N][MAX_N]) {
    for (size_t i = 0; i < MAX_N; i++) {
        for (size_t j = 0; j < MAX_N; j++) {
            mat[i][j] = false;
        }
    }
}
