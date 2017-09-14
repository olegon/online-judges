/*
A Última Criança Boa
https://www.urionlinejudge.com.br/judge/pt/problems/view/2023
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<string, string> ss;

int main(void) {
    ios::sync_with_stdio(false);

    string nome;
    vector<ss> nomes;

    while (getline(cin, nome)) {
        auto p = make_pair(nome, nome);

        for (auto it = p.second.begin(); it != p.second.end(); ++it) {
            *it = tolower(*it);
        }

        nomes.push_back(p);
    }

    sort(nomes.begin(), nomes.end(), [] (ss a, ss b) -> bool {
        return a.second > b.second;
    });

    cout << nomes[0].first << endl;

    return EXIT_SUCCESS;
}
