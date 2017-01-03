/*
Fibonacci Rápido
https://www.urionlinejudge.com.br/judge/pt/problems/view/2164
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double fib(int n);

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N;
    cout << fixed << setprecision(1) << fib(N) << '\n';

    return 0;
}

double fib(int n) {
    double sqrtOf5 = sqrt(5);

    return (pow((1 + sqrtOf5) / 2, n) - pow((1 - sqrtOf5) / 2, n)) / sqrtOf5;
}
