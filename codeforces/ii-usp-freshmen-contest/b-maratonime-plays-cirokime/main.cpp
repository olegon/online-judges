/*
B. MaratonIME plays Cîrokime
http://codeforces.com/gym/100985/problem/B
*/

#include <bits/stdc++.h>

using namespace std;

size_t ulog(size_t n);

int main(void) {
    ios::sync_with_stdio(false);

    size_t N;

    cin >> N;

    cout << ulog(N) << endl;

    return EXIT_SUCCESS;
}


size_t ulog(size_t n) {
    size_t q = 1;

    while (n > 1) {
        q++;
        n /= 2;
    }

    return q;
}