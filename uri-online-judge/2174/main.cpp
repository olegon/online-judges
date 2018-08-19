/*
Coleção de Pomekon
https://www.urionlinejudge.com.br/judge/pt/problems/view/2174
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N;
    set<string> pomekons;

    cin >> N >> ws;

    while (N-- > 0) {
        string line;

        getline(cin, line);

        pomekons.insert(line);
    }

    cout << "Falta(m) " << (151 - pomekons.size()) << " pomekon(s)." << endl;

    return EXIT_SUCCESS;
}
