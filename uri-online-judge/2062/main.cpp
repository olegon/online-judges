/*
OBI URI
https://www.urionlinejudge.com.br/judge/pt/problems/view/2062
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    while (N-- > 0) {
        string word;

        cin >> word;

        if (word.length() == 3) {
            string substr = word.substr(0, 2);

            if (substr == "UR") {
                cout << "URI";
            }
            else if (substr == "OB") {
                cout << "OBI";
            }
            else {
                cout << word;
            }
        }
        else {
            cout << word;
        }

        if (N != 0) cout << " ";
    }

    cout << endl;

    return EXIT_SUCCESS;
}
