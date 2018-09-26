/*
Minimum Absolute Difference in an Array
https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/problem
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N,
        result = INT_MAX;

    cin >> N;

    vector<int> numbers(N);

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    for (int i = 1; i < N; i++) {
        result = min(result, numbers[i] - numbers[i - 1]);
    }

    cout << result << endl;

    return EXIT_SUCCESS;
}
