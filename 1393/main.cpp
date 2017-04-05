/*
Lajotas Hexagonais
https://www.urionlinejudge.com.br/judge/pt/problems/view/1393
*/

#include <iostream>
#include <cstdlib>

using namespace std;

typedef unsigned long long int uint64;

int main(void) {
    ios::sync_with_stdio(false);    

    uint64 fb[40 + 1];

    fb[1] = 1;
    fb[2] = 2;

    for (int i = 3; i <= 40; i++) {
        fb[i] = fb[i - 1] + fb[i - 2];
    }

    int N;   

    while (cin >> N, N != 0) cout << fb[N] << '\n';

    return EXIT_SUCCESS;
}