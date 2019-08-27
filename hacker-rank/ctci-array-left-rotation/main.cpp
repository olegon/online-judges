/*
Arrays: Left Rotation
https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N, D;

    cin >> N >> D;

    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int skip = D % N;
    bool space = false;

    for (int i = skip; i < N; i++) {
        if (space) {
            cout << " " << A[i];
        }
        else {
            cout << A[i];
            space = true;
        }
    }

    for (int i = 0; i < skip; i++) {
        if (space) {
            cout << " " << A[i];
        }
        else {
            cout << A[i];
            space = true;
        }
    }

    cout << endl;

    return EXIT_SUCCESS;
}
