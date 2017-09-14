/*
Paridade
https://www.urionlinejudge.com.br/judge/pt/problems/view/2176
*/

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    string bits;

    getline(cin, bits);

    bool par = true;
    
    for (auto it = bits.begin(); it != bits.end(); ++it) {
      if (*it == '1') par = !par;
    }

    cout << bits;

    if (par) {
      cout << '0';
    }
    else {
      cout << '1';
    }

    cout << endl;

    return 0;
}
