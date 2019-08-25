/*
Repeated String
https://www.hackerrank.com/challenges/repeated-string/problem
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int uint64;

uint64 countOcurrences(string &S, uint64 N) {
    uint64 ocurr = 0;

    for (auto c : S) {
        if (c == 'a') ocurr++;
    }

    uint64 m = N / S.length();
    ocurr = ocurr * m;

    for (uint64 i = m * S.length(); i < N; i++) {
        if (S[i % S.length()] == 'a') ocurr++;
    }

    return ocurr;
}

int main(void) {
    ios::sync_with_stdio(false);

    string S;
    uint64 N;

    getline(cin, S);
    cin >> N;

    cout << countOcurrences(S, N) << endl;

    return EXIT_SUCCESS;
}
