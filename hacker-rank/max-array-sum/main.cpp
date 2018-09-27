/*
Max Array Sum
https://www.hackerrank.com/challenges/max-array-sum/problem
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

struct calculation {
    int64 value;
    bool calculated; 
};

int64 maxArraySum(const vector<int> &sequence, size_t i, vector<calculation> &dp) {
    if (i >= sequence.size()) return 0;

    if (!dp[i].calculated) {
        dp[i].value = max(
            sequence[i] + maxArraySum(sequence, i + 2, dp),
            maxArraySum(sequence, i + 1, dp)
        );
        dp[i].calculated = true;
    }

    return dp[i].value; 
}

int64 maxArraySum(const vector<int> &sequence) {
    vector<calculation> dp(sequence.size(), { 0, false });

    return maxArraySum(sequence, 0, dp);
}

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    vector<int> sequence(N);

    for (int i = 0; i < N; i++) {
        cin >> sequence[i];
    }

    cout << maxArraySum(sequence) << endl;

    return EXIT_SUCCESS;
}
