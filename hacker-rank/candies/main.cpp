/*
Candies
https://www.hackerrank.com/challenges/candies/problem
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N;
    unsigned long long total = 0;

    cin >> N;

    vector<int> ratings(N), candies(N);

    for (int i = 0; i < N; i++) cin >> ratings[i];

    candies[0] = 1;
    for (int i = 1; i < N; i++) {
        if (ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
        else candies[i] = 1;
    }

    // cout << candies[0];
    // for (int i = 1; i < N; i++) {
    //     cout << " " << candies[i];
    // }
    // cout << endl;

    for (int i = N - 2; i > -1; i--) {
        if (ratings[i] > ratings[i + 1]) candies[i] = max(candies[i + 1] + 1, candies[i]);
    }

    // cout << candies[0];
    // for (int i = 1; i < N; i++) {
    //     cout << " " << candies[i];
    // }
    // cout << endl;

    for (int i = 0; i < N; i++) {
        total += candies[i];
    }

    cout << total << endl;

    return EXIT_SUCCESS;
}
