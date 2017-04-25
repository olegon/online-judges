/*
Arredondamento por Valor de Corte
https://www.urionlinejudge.com.br/judge/pt/problems/view/1305
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    double number, cutoff;
    
    while (cin >> number >> cutoff) {
        double dNumber = number - int(number);
        double dCutoff = cutoff - int(cutoff);

        if (dNumber > dCutoff) {
            cout << int(number) + 1 << '\n';
        }
        else {
            cout << int(number) << '\n';
        }
    }

    return EXIT_SUCCESS;
}