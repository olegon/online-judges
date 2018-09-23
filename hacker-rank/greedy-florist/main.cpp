/*
Greedy Florist
https://www.hackerrank.com/challenges/greedy-florist/problem
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N, K;
    int minPrice = 0;

    cin >> N >> K;

    vector<int> prices(N);

    for (int i = 0; i < N; i++) {
        cin >> prices[i];
    }

    sort(prices.begin(), prices.end(), [] (int a, int b) {
        return a > b;
    });

    for (int i = 0; i < K; i++) {
        minPrice += prices[i];
    }
    
    int j = K;
    int i = 0;
    while (j < N) {
        int prev = (i / K) + 2;
        minPrice += prices[j] * prev;

        j++;
        i++;
    }

    cout << minPrice << endl;

    return EXIT_SUCCESS;
}
