/*
Abracadabra
https://www.urionlinejudge.com.br/judge/pt/problems/view/2484
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    string line;

    while (getline(cin, line)) {
        size_t length = line.length();

        for (size_t i = 0; i < length; i++) {
            for (size_t j = 0; j < i; j++) cout << ' ';

            for (size_t j = 0; j < length - i; j++) {
                cout << line[j];
                
                if (j < length - i - 1) cout << ' ';
            }

            cout << '\n';
        }

        cout << '\n';
    }

    return EXIT_SUCCESS;
}
