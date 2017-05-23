/*
Handebol
https://www.urionlinejudge.com.br/judge/pt/problems/view/1715
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N,
        M,
        r = 0;

    cin >> N >> M;

    while (N-- > 0) {
        bool golEmTodas = true;

        for (int i = 0; i < M; i++) {
            int gols;

            cin >> gols;

            golEmTodas = golEmTodas && gols > 0;
        }

        if (golEmTodas) r++;
    }

    cout << r << endl;

    return EXIT_SUCCESS;
}
