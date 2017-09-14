/*
Volta
https://www.urionlinejudge.com.br/judge/pt/problems/view/1708
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int X, Y;

    cin >> X >> Y;

    cout << fixed << setprecision(0) << ceil(1.0 * X / (Y - X)) + 1.0 << endl;

    return EXIT_SUCCESS;
}
