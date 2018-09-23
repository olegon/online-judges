/*
Compare the Triplets
https://www.hackerrank.com/challenges/compare-the-triplets/problem
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    vector<int> A(3), B(3);
    int a = 0,
        b = 0;

    for (size_t i = 0; i < 3; i++) cin >> A[i];

    for (size_t i = 0; i < 3; i++) cin >> B[i];

    for (size_t i = 0; i < 3; i++) {
        if (A[i] > B[i]) a++;
        else if (B[i] > A[i]) b++;
    }

    cout << a << " " << b << endl;

    return EXIT_SUCCESS;
}
