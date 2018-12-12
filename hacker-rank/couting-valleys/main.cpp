/*
Counting Valleys
https://www.hackerrank.com/challenges/counting-valleys
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    int n;
    cin >> n >> ws;

    string map;
    cin >> map;

    int level = 0,
        count = 0;

    for (auto c : map) {
        if (c == 'U') {
            if (level == -1) {
                count++;
            }

            level++;
        }
        else {
            level--;
        }
    }

    cout << count << endl;

    return EXIT_SUCCESS;
}
