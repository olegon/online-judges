/*
Recursion: Fibonacci Numbers
https://www.hackerrank.com/challenges/ctci-fibonacci-numbers/problem
*/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int uint64;

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    vector<uint64> dp(N + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[N] << endl;

    return EXIT_SUCCESS;
}
