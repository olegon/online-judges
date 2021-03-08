/*
Missing Numbers
https://www.hackerrank.com/challenges/missing-numbers/problem
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int M, N;
    vector<int> ARR(10001, 0);

    cin >> M;

    for (int i = 0; i < M; i++) {
        int number;
        
        cin >> number;

        ARR[number]++;
    }

    cin >> N;

    for (int i = 0; i < N; i++) {
        int number;
        
        cin >> number;

        ARR[number]--;
    }

    bool appendSpace = false;
    for (int i = 0; i < 10001; i++) {
        if (ARR[i] < 0) {
            if (appendSpace) {
                cout << " " << i;
            }
            else {
                appendSpace = true;
                cout << i;
            }
        }
    }
    cout << endl;

    return EXIT_SUCCESS;
}
