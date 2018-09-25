/*
Abbreviation
https://www.hackerrank.com/challenges/abbr/problem
*/

#include <bits/stdc++.h>

using namespace std;

enum state {
    NONE = 0,
    OK = 1,
    NOK = 2
};


bool canTransform(const string &a, const string &b, size_t ia, size_t ib, vector< vector<state> > &dp) {
    // cout << ia << " " << ib << endl;

    if (dp[ia][ib] == NONE) {
        bool result;

        // Se as duas string foram até o final
        if (ia >= a.length() && ib >= b.length()) {
            result = true;
        }
        // Se somente a foi até o final
        else if (ia >= a.length()) {
            result = false;
        }
        // Se somente b foi até o final, não pode haver maiúscular em a.
        else if (ib >= b.length()) {
            result = islower(a[ia]) && canTransform(a, b, ia + 1, ib, dp);
        }
        // Se são iguais (a[ia] é maiúsculo), avançar a e b
        else if (a[ia] == b[ib]) {
            result = canTransform(a, b, ia + 1, ib + 1, dp);
        }
        // Se a[ia] for b[ib] minúscula, analisar obter e não obter.
        else if (toupper(a[ia]) == b[ib]) {
            result = canTransform(a, b, ia + 1, ib, dp) || canTransform(a, b, ia + 1, ib + 1, dp);
        }
        // Se a[ia] é maiúsculo e diferente de b[ib]
        else if (isupper(a[ia])) {
            result = false;
        }
        // Se a[ia] é minúsculo e diferente de b[ib]
        else {
            result = canTransform(a, b, ia + 1, ib, dp);
        }

        dp[ia][ib] = result ? OK : NOK;
    }

    return dp[ia][ib] == OK;
}

bool canTransform(const string &a, const string &b) {
    vector< vector<state> > dp(a.length() + 1, vector<state>(b.length() + 1, NONE));

    return canTransform(a, b, 0, 0, dp);
}

int main(void) {
    ios::sync_with_stdio(false);

    int q;

    cin >> q >> ws;

    while (q-- > 0) {
        string a, b;

        getline(cin, a);
        getline(cin, b);

        // cout << a << endl;
        // cout << b << endl;

        if (canTransform(a, b)) cout << "YES";
        else cout << "NO";

        cout << endl;
    }

    return EXIT_SUCCESS;
}
