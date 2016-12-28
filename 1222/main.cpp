/*
Concurso de Contos
https://www.urionlinejudge.com.br/judge/pt/problems/view/1222
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N, L, C;

    while (cin >> N >> L >> C) {
        string line, word;

        cin.ignore(1);

        getline(cin, line);

        stringstream ss(line);

        int columns = 0,
            lines = 0,
            pages = 0;

        while (ss >> word) {
            if (columns + word.length() == C) {
                columns = 0;
                lines++;
            }
            else if (columns + word.length() > C) {
                columns = word.length() + 1;
                lines++;
            }
            else {
                columns += word.length() + 1;
            }

            if (lines == L) {
                pages++;
                lines = 0;
            }
        }

        if (lines > 0 || columns > 0) pages++;

        cout << pages << '\n';
    }

    return 0;
}
