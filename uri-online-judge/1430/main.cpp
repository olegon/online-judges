/*
Composição de Jingles
https://www.urionlinejudge.com.br/judge/pt/problems/view/1430
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

const double EPSILON = 0.00001;

double duracao(char nota);

int main(void) {
    ios::sync_with_stdio(false);

    string line;
    while (getline(cin, line), line != "*") {
        stringstream ss(line);
        string compasso;

        int compassosCorretos = 0;

        getline(ss, compasso, '/'); // primeiro compasso sempre está vazio

        while (getline(ss, compasso, '/')) {
            double tempo = 0.0;

            for (auto it = compasso.begin(); it != compasso.end(); ++it) {
                tempo += duracao(*it);
            }

            if (abs(1.0 - tempo) < EPSILON) compassosCorretos++;
        }

        cout << compassosCorretos << '\n';
    }

    return 0;
}

double duracao(char nota) {
    switch (nota) {
        case 'W':
            return 1.0 / 1.0;
        case 'H':
            return 1.0 / 2.0;
        case 'Q':
            return 1.0 / 4.0;
        case 'E':
            return 1.0 / 8.0;
        case 'S':
            return 1.0 / 16.0;
        case 'T':
            return 1.0 / 32.0;
        case 'X':
            return 1.0 / 64.0;
        default:
            cerr << "DURACAO NAO DEFINIDA" << endl;
            abort();

    }
}
