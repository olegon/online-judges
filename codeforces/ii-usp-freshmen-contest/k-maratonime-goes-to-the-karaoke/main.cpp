/*
B. MaratonIME plays Cîrokime
http://codeforces.com/gym/100985/problem/B
*/

#include <bits/stdc++.h>

using namespace std;

size_t ulog(size_t n);

int main(void) {
    ios::sync_with_stdio(false);

    string S;

    getline(cin, S);

    if (S.size() > 0) {
        char current = S[0];
        int count = 1;

        for (size_t i = 1; i < S.size(); i++) {
            if (S[i] == current) count++;
            else {
                cout << current << count;

                current = S[i];
                count = 1;
            }
        }

        cout << current << count;
    }

    cout << endl;

    return EXIT_SUCCESS;
}