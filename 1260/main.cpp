/*
Espécies de Madeira
https://www.urionlinejudge.com.br/judge/pt/problems/view/1260
*/

#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N;
    string especie;

    cin >> N >> ws;

    while (N-- > 0) {
        map<string, int> especies;
        int quantidade = 0;

        while (getline(cin, especie)) {
            if (especie == "") break;

            auto it = especies.find(especie);

            if (it != especies.end()) {
                it->second += 1;
            }
            else {
                especies.insert(make_pair(especie, 1));
            }
            
            quantidade += 1;
        }

        for (auto p : especies) {
            cout << p.first << " " << fixed << setprecision(4) << (100.0 * p.second / quantidade) << '\n';
        }

        if (N != 0) cout << '\n';
    }



    return EXIT_SUCCESS;
}
