/*
Trilhos Novamente... Traçando Movimentos
https://www.urionlinejudge.com.br/judge/pt/problems/view/1063
*/

#include <iostream>
#include <cstdlib>
#include <deque>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    while (cin >> N >> ws, N != 0) {
        deque<char> in;
        deque<char> out;
        deque<char> station;

        for (int i = 0; i < N; i++) {
            char vagao;

            cin >> vagao >> ws;

            in.push_back(vagao);
        }

        for (int i = 0; i < N; i++) {
            char vagao;

            cin >> vagao >> ws;

            out.push_back(vagao);
        }

        while (!in.empty()) {
            char vagao = in.front();
            in.pop_front();

            station.push_back(vagao);
            cout << "I";

            while (!station.empty() && station.back() == out.front()) {
                station.pop_back();
                out.pop_front();
                cout << "R";
            }
        }

        if (station.empty()) {
            cout << '\n';
        }
        else {
            cout << " Impossible\n";

        }

    }


    return EXIT_SUCCESS;
}
