/*
Ele Está Impedido!
http://www.urionlinejudge.com.br/forum/viewtopic.php?f=3&t=412
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int A, D;

    while (cin >> A >> D, A != 0 || D != 0) {
        vector<int> atacantes;
        vector<int> defensores;

        for (int i = 0; i < A; i++) {
            int atacante; 

            cin >> atacante;

            atacantes.push_back(atacante);
        }

        for (int i = 0; i < D; i++) {
            int defensor; 

            cin >> defensor;

            defensores.push_back(defensor);
        }

        sort(atacantes.begin(), atacantes.end());
        sort(defensores.begin(), defensores.end());

        if (atacantes[0] < defensores[0] || atacantes[0] < defensores[1]) {
            cout << "Y\n";
        }
        else {
            cout << "N\n";
        }
    }

    return 0;
}
