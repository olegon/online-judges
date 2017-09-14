/*
Fases da Lua
https://www.urionlinejudge.com.br/judge/pt/problems/view/1893
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int A, B;

    cin >> A >> B;

    if (B < 3) {
        cout << "nova";
    }
    else if (B < 97) {
        if (A < B) {
            cout << "crescente";
        }
        else {
            cout << "minguante";
        }
    }
    else {
        cout << "cheia";
    }

    cout << endl;

    return EXIT_SUCCESS;
}
