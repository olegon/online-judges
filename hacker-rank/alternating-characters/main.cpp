/*
Alternating Characters
https://www.hackerrank.com/challenges/alternating-characters
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int Q;

    cin >> Q >> ws;

    while (Q-- > 0) {
        string line;

        getline(cin, line);
        
        int toDelete = 0;
        char currentLetter = line[0];

        for (size_t i = 1; i < line.length(); i++) {
            if (line[i] == currentLetter) toDelete++;
            else currentLetter = line[i];
        }

        cout << toDelete << endl;
    }


    return EXIT_SUCCESS;
}
