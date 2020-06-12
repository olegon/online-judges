/*
Balanced Brackets
https://www.hackerrank.com/challenges/balanced-brackets
*/

#include <bits/stdc++.h>

using namespace std;


bool isBalanced(string &expression) {
    stack<char> tokens;

    for (auto c : expression) {
        switch (c) {
            case '{':
            case '[':
            case '(':
                tokens.push(c);

                break;
            case '}':
                if (tokens.empty() || tokens.top() != '{')
                    return false;

                tokens.pop();

                break;
            case ']':
                if (tokens.empty() || tokens.top() != '[')
                    return false;

                tokens.pop();

                break;
            case ')':
                if (tokens.empty() || tokens.top() != '(')
                    return false;

                tokens.pop();

                break;
            default:
                break;
        }
    }

    return tokens.empty();
}

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N >> ws;

    while (N-- > 0) {
        string line;

        getline(cin, line);

        cout << (isBalanced(line) ? "YES" : "NO") << endl;
    }

    return EXIT_SUCCESS;
}
