/*
Elevador
https://www.urionlinejudge.com.br/judge/pt/problems/view/1124
*/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int L, C, R1, R2;

    while (cin >> L >> C >> R1 >> R2, L != 0 || C != 0 || R1 != 0 || R2 != 0) {
        if (2 * R1 <= L
            && 2 * R2 <= L
            && 2 * R1 <= C
            && 2 * R2 <= C
            && sqrt(pow(R1 + R2 - C, 2) + pow(R1 + R2 - L, 2)) >= 1.0 * R1 + R2) {
            cout << "S\n";
        }
        else {
            cout << "N\n";
        }
    }

    return EXIT_SUCCESS;
}
