/*
Picos e Vales
https://www.urionlinejudge.com.br/judge/pt/problems/view/2162
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N,
        prev, curr;

    cin >> N;

    cin >> prev >> curr;

    if (N == 2) {
        cout << (prev != curr ? 1 : 0) << endl;
    }
    else {
        bool mustBeGreater = curr < prev;
        bool valid = true;

        for (int i = 2; i < N; i++) {
            prev = curr;

            cin >> curr;

            valid = valid && prev != curr && (curr > prev) == mustBeGreater;

            mustBeGreater = !mustBeGreater;
        }

        cout << (valid ? 1 : 0) << endl;
    }

    return EXIT_SUCCESS;
}
