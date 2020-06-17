/*
String Construction
https://www.hackerrank.com/challenges/string-construction
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N >> ws;

    while (N-- > 0) {
        string word;
        int cost = 0;
        vector<bool> seenLetters('z' - 'a' + 1, false);

        cin >> word;

        for (auto letter : word) {
            if (seenLetters[letter - 'a']) {
                continue;
            }
            else {
                cost++;
                seenLetters[letter - 'a'] = true;
            }
        }

        cout << cost << endl;
    }

    return EXIT_SUCCESS;
}
