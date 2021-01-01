/*
Mark and Toys
https://www.hackerrank.com/challenges/mark-and-toys
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    
    int N, K;

    cin >> N >> K;

    vector<int> PRICES(N);

    for (int i = 0; i < N; i++) {
        cin >> PRICES[i];
    };

    sort(PRICES.begin(), PRICES.end());

    int toysCount = 0;

    for (int i = 0; i < N; i++) {
        if (PRICES[i] > K) break;

        K -= PRICES[i];
        toysCount++;
    };

    cout << toysCount << endl;

    return EXIT_SUCCESS;
}
