/*
II USP Freshmen Contest (http://codeforces.com/gym/100985)
G. MaratonIME goes rowing (http://codeforces.com/gym/100985/problem/G)
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    string S;

    getline(cin, S);
    
    int p = 0;
    for (auto c : S) {
        if (c == 'A') p++;
        else p--;
        
        if (p < 0) break;
    }

    if (p == 0) cout << "Sim" << endl;
    else cout << "Nao" << endl;

    return EXIT_SUCCESS;
}
