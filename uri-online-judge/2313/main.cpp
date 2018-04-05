/*
Qual Triângulo
https://www.urionlinejudge.com.br/judge/pt/problems/view/2313
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    vector<int> sides;

    for (int i = 0; i < 3; i++) {
        int side;
        
        cin >> side;
        
        sides.push_back(side);
    }

    sort(sides.begin(), sides.end());

    if (sides[0] + sides[1] <= sides[2]) {
        cout << "Invalido" << endl;
    }
    else {
        if (sides[0] == sides[1] && sides[1] == sides[2]) {
            cout << "Valido-Equilatero\n";
        }
        else if (sides[0] == sides[1] || sides[1] == sides[2]) {
            cout << "Valido-Isoceles\n";
        }
        else {
            cout << "Valido-Escaleno\n";
        }

        if (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2]) {
            cout << "Retangulo: S" << endl;
        }
        else {
            cout << "Retangulo: N" << endl;
        }
        
    }


    return EXIT_SUCCESS;
}
