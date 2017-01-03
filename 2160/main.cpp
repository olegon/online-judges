/*
Nome no Formulário
https://www.urionlinejudge.com.br/judge/pt/problems/view/2160
*/

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    string line;

    getline(cin, line);

    if (line.length() > 80) cout << "NO\n";
    else cout << "YES\n";

    return 0;
}
