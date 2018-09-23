/*
Luck Balance
https://www.hackerrank.com/challenges/luck-balance/problem
*/

#include <bits/stdc++.h>

using namespace std;

struct contest {
    int L, T;
};

int main(void) {
    ios::sync_with_stdio(false);

    int N, K;
    vector<contest> contests;
    int total = 0;

    cin >> N >> K;
 
    for (int i = 0; i < N; i++) {
        int L, T;

        cin >> L >> T;

        contests.push_back({ L, T });
    }

    sort(contests.begin(), contests.end(), [] (const contest &a, const contest &b) {
        if (a.T == b.T) return a.L > b.L;
        else return a.T < b.T;
    });

    for (auto &c : contests) {
        if (c.T == 0 || K-- > 0) {
            total += c.L;
        }
        else {
            total -= c.L;
        }
    }

    cout << total << endl;

    return EXIT_SUCCESS;
}
