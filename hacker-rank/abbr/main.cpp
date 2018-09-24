/*
Abbreviation
https://www.hackerrank.com/challenges/abbr/problem
*/

#include <bits/stdc++.h>

using namespace std;


bool canTransform(const string &a, const string &b, size_t ia, size_t ib) {
    // cout << ia << " " << ib << endl;

    // Se as duas string foram até o final
    if (ia >= a.length() && ib >= b.length()) {
        return true;
    }

    // Se somente a foi até o final
    if (ia >= a.length()) {
        return false;
    }

    // Se somente b foi até o final, não pode haver maiúscular em a.
    if (ib >= b.length()) {
        return islower(a[ia]) && canTransform(a, b, ia + 1, ib);
    }
    
    // Se são iguais (a[ia] é maiúsculo), avançar a e b
    if (a[ia] == b[ib]) {
        return canTransform(a, b, ia + 1, ib + 1);
    }

    // Se a[ia] for b[ib] minúscula, analisar obter e não obter.
    if (toupper(a[ia]) == b[ib]) {
        return canTransform(a, b, ia + 1, ib) || canTransform(a, b, ia + 1, ib + 1);
    }

    // Se a[ia] é maiúsculo e diferente de b[ib]
    if (isupper(a[ia])) {
        return false;
    }

    // Se a[ia] é minúsculo e diferente de b[ib]
    return canTransform(a, b, ia + 1, ib);
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

        if (canTransform(a, b, 0, 0)) cout << "YES";
        else cout << "NO";

        cout << endl;
    }

    return EXIT_SUCCESS;
}
