/*
Raiz Quadrada de 10
https://www.urionlinejudge.com.br/judge/pt/problems/view/2161
*/

#include <iostream>
#include <iomanip>

using namespace std;

double sqrt10(int n);
double div1by6(int n);

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    cout << fixed << setprecision(10) << sqrt10(N) << endl;

    return 0;
}

double sqrt10(int n) {
    return 3.0 + div1by6(n);
}

double div1by6(int n) {
    if (n == 0) return 0.0;
    else return 1.0 / (6 + div1by6(n - 1));
}
