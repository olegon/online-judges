/*
Tuitando
https://www.urionlinejudge.com.br/judge/pt/problems/view/2165
*/

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    string line;

    getline(cin, line);

    if (line.length() > 140) cout << "MUTE\n";
    else cout << "TWEET\n";

    return 0;
}
