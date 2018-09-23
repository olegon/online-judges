/*
Max Min
https://www.hackerrank.com/challenges/angry-children/problem
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N, K;
    int response = INT_MAX;

    cin >> N >> K;

    vector<int> numbers(N);

    for (int i = 0; i < N; i++) cin >> numbers[i];

    sort(numbers.begin(), numbers.end());

    for (int i = 0; i + K - 1 < N; i++) {
        response = min(response, numbers[i + K - 1] - numbers[i]);
    }

    cout << response << endl;

    return EXIT_SUCCESS;
}
