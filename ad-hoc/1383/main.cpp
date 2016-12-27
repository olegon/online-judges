/*
Sudoku
https://www.urionlinejudge.com.br/judge/pt/problems/view/1383
*/

#include <iostream>
#include <set>

using namespace std;

bool ganhou(const int mat[9][9]);

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int mat[9][9];

        for (int m = 0; m < 9; m++) {
            for (int n = 0; n < 9; n++) {
                cin >> mat[m][n];
            }
        }

        cout << "Instancia " << i << '\n';
        if (ganhou(mat)) cout << "SIM\n";
        else cout << "NAO\n";
        cout << '\n';
    }

    return 0;
}

bool ganhou(const int mat[9][9]) {
    for (int i = 0; i < 9; i++) {
        set<int> s;

        for (int j = 0; j < 9; j++) {
            s.insert(mat[i][j]);
        }

        if (s.size() < 9) return false;
    }

    for (int i = 0; i < 9; i++) {
        set<int> s;

        for (int j = 0; j < 9; j++) {
            s.insert(mat[j][i]);
        }

        if (s.size() < 9) return false;
    }

    for (int m = 0; m < 9; m += 3) {
        for (int n = 0; n < 9; n += 3) {
            set<int> s;

            for (int i = m; i < m + 3; i++) {
                for (int j = n; j < n + 3; j++) {
                    s.insert(mat[i][j]);
                }
            }

            if (s.size() < 9) return false;
        }
    }

    return true;
}
