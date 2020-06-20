/*
Sherlock and the Valid String
https://www.hackerrank.com/challenges/sherlock-and-valid-string
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    string line;

    getline(cin, line);

    vector<int> ocorrencies('z' - 'a' + 1, 0);

    for (char c : line) {
        ocorrencies[c - 'a']++;
    }

    int a = -1,
        b = -1;

    for (int q : ocorrencies) {
        // cout << q << endl;

        if (a == q || q == 0) continue;
        if (a == -1) a = q;
        else if (a != q && b == -1) b = q;
        else {
            a = b = -1;
            break;
        }
    }

    // cout << "a = " << a << endl;
    // cout << "b = " << b << endl;

    if (a == -1 && b == -1) cout << "NO" << endl;
    else cout << "YES" << endl;


    return EXIT_SUCCESS;
}
