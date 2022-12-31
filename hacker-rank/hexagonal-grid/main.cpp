/*
Hexagonal Grid
https://www.hackerrank.com/challenges/hexagonal-grid
*/

#include <bits/stdc++.h>

using namespace std;


bool calc(size_t i, size_t j, size_t N, vector<vector<int>> &map) {
    // cout << "i = " << i << "; ";
    // cout << "j = " << j << "; ";
    // cout << endl;
    // for (size_t _i = 0; _i < 2; _i++) {
    //     for (size_t _j = 0; _j < N; _j++) {
    //         cout << map[_i][_j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    

    if (i >= 2) return true;

    if (j >= N) return calc(i + 1, 0, N, map);

    int field = map[i][j];

    if (field == 1 || field == 2) return calc(i, j + 1, N, map);

    if (i == 0 && map[i + 1][j] == 0) {
        map[i][j] = 2;
        map[i + 1][j] = 2;

        bool correct = calc(i, j + 1, N, map);

        if (correct) return true;
        else {
            map[i][j] = 0;
            map[i + 1][j] = 0;
        }
    }

    if (i == 0 && j > 0 && map[i + 1][j - 1] == 0) {
        map[i][j] = 2;
        map[i + 1][j - 1] = 2;

        bool correct = calc(i, j + 1, N, map);

        if (correct) return true;
        else {
            map[i][j] = 0;
            map[i + 1][j - 1] = 0;
        }
    }

    if (j + 1 < N && map[i][j + 1] == 0) {
        map[i][j] = 2;
        map[i][j + 1] = 2;

        bool correct = calc(i, j + 1, N, map);

        if (correct) return true;
        else {
            map[i][j] = 0;
            map[i][j + 1] = 0;
        }
    }

    if (field == 0) return false;

    return calc(i, j + 1, N, map);
}

int main(void) {
    ios::sync_with_stdio(false);

    size_t T;
    cin >> T >> ws;

    while (T-- > 0) {
        size_t N;
        cin >> N >> ws;

        vector<vector<int>> map(2, vector<int>(N));

        for (size_t i = 0; i < 2; i++) {
            string line;
            cin >> line >> ws;

            for (size_t j = 0; j < N; j++) {
                map[i][j] = line[j] == '1' ? 1 : 0;
            }
        }

        cout << (calc(0, 0, N, map) ? "YES" : "NO") << endl;
    }

    return EXIT_SUCCESS;
}
