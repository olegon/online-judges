/*
Two Strings
https://www.hackerrank.com/challenges/two-strings
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int P;

    cin >> P >> ws;

    while (P-- > 0) {
        string lineA, lineB;
        bool valid = false;

        getline(cin, lineA);
        getline(cin, lineB);

        vector<int> hash('z' - 'a' + 1, 0);

        for (char c : lineA) {
            hash[c - 'a']++;
        }

        for (char c : lineB) {
            if (hash[c - 'a'] > 0) {
                valid = true;
                break;
            }
        }

        cout << (valid ? "YES" : "NO") << endl;
    }

    return EXIT_SUCCESS;
}
