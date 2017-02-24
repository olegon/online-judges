/*
Apagando e Ganhando
https://www.urionlinejudge.com.br/judge/pt/problems/view/1084
*/

#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N, D;

    while (cin >> N >> D >> ws, N != 0 || D != 0) {
        string number;
        list<char> l;

        int size = N;
        int desiredSize = N - D;

        getline(cin, number);

        for (int i = 0; i < N; i++) {
            l.push_back(number[i]);
        }    

        while (size > desiredSize) {
            auto min = l.begin();

            for (auto it = l.begin(); it != l.end(); ++it) {
                if (*it < *min) min = it;

                if (*min == '0') break;
            }

            l.erase(min);
            size--;
        }

        for (auto it = l.begin(); it != l.end(); ++it) {
            cout << *it;
        }      

        cout << '\n';
    }    

    return EXIT_SUCCESS;
}
