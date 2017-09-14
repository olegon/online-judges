/*
Flíper
https://www.urionlinejudge.com.br/judge/pt/problems/view/2454
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int P, R;

    cin >> P >> R;

    if (P == 0) cout << "C";
    else if (R == 0) cout << "B";
    else cout << "A";

    cout << endl;

    return EXIT_SUCCESS;
}
