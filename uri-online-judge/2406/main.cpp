/*
Expressões
https://www.urionlinejudge.com.br/judge/pt/problems/view/2406
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N >> ws;

    while (N-- > 0) {
        string expression;
        stack<char> elements;
        bool valid = true;
        
        getline(cin, expression);


        for (char el : expression) {
            if (el == '{' || el == '[' || el == '(') {
                elements.push(el);
            }
            else if (elements.empty()) {
                valid = false;
            }
            else {
                char opening = elements.top();
                elements.pop();

                if (el == '}' && opening != '{'
                    || el == ']' && opening != '['
                    || el == ')' && opening != '(') {
                    valid = false;
                }
            }

            if (!valid) break;
        }

        if (valid && elements.empty()) {
            cout << "S" << endl;
        }
        else {
            cout << "N" << endl;
        }
    }

    return EXIT_SUCCESS;
}
