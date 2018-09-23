/*
A Very Big Sum
https://www.hackerrank.com/challenges/a-very-big-sum/problem?h_r=next-challenge&h_v=zen
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N;
    unsigned long long int total = 0, value;

    cin >> N;

    while (N-- > 0) {
        cin >> value;

        total += value;
    }

    cout << total << endl;

    return EXIT_SUCCESS;
}
