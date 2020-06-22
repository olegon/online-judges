/*
Highest Value Palindrome
https://www.hackerrank.com/challenges/richie-rich
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N, K;
    string number;

    cin >> N >> K >> ws;

    vector<bool> indexChanged(N, false);

    getline(cin, number);

    for (size_t i = 0; i < number.length() / 2; i++) {
        char left = number[i];
        char right = number[number.length() - 1 - i];
        if (left != right) {
            number[i] = number[number.length() - 1 - i] = max(left, right);
            indexChanged[i] = true;
            K -= 1;
        }
    }

    if (K >= 0) {
        for (size_t i = 0; i < number.length() / 2 && K > 0; i++) {
            if (number[i] != '9' && indexChanged[i] && K > 0) {
                number[i] = number[number.length() - 1 - i] = '9';
                K -= 1;
            }

            if (number[i] != '9' && !indexChanged[i] && K > 1) {
                number[i] = number[number.length() - 1 - i] = '9';
                K -= 2;
            }
        }

        if (N % 2 == 1 && K > 0 && number[number.length() / 2] != '9') {
            number[number.length() / 2] = '9';
            K -= 1;
        }

        cout << number << endl;
    }
    else {
        cout << -1 << endl;
    }


    return EXIT_SUCCESS;
}
