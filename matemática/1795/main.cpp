/*
Triângulo Trinomial
https://www.urionlinejudge.com.br/judge/pt/problems/view/1795
*/

#include <iostream>

using namespace std;

typedef unsigned long long int uint64;

uint64 pow(uint64 base, int expoent);

int main(void) {
    ios::sync_with_stdio(false);

    uint64 N;

    cin >> N;

    cout << pow(3, N) << '\n';

    return 0;
}

uint64 pow(uint64 base, int expoent) {
    if (expoent == 0) {
        return 1;
    }
    else {
        int half_exporent = expoent / 2;

        uint64 result = pow(base, half_exporent) * pow(base, half_exporent);

        if (expoent % 2 == 0) return result;
        else return result * base;
    }
}
