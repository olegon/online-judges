/*
Formiguinha
https://www.urionlinejudge.com.br/judge/pt/problems/view/1612
*/

#include <iostream>
#include <cstdlib>


using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int T;

    cin >> T;

    while(T-- > 0) {
        int N;

        cin >> N;

        cout << (N - 1) / 2 + 1 << '\n';
    }

    return EXIT_SUCCESS;
}
