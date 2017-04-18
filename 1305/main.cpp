/*
Arredondamento por Valor de Corte
https://www.urionlinejudge.com.br/judge/pt/problems/view/1305
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

size_t getIntegerPart(const string &number);
string getDecimalPart(const string &number);
bool strGreater(const string &a, const string &b);

int main(void) {
    ios::sync_with_stdio(false);

    string number, cutoff;
    
    while (getline(cin, number)) {
        getline(cin, cutoff);

        if (strGreater(getDecimalPart(number), getDecimalPart(cutoff))) {
            cout << getIntegerPart(number) + 1 << '\n';
        }
        else {
            cout << getIntegerPart(number) << '\n';
        }
    }

    return EXIT_SUCCESS;
}

size_t getIntegerPart(const string &number) {
    size_t integer = 0, base = 1;
    stack<char> integerStack;

    // cout << "getIntegerPart(" << number << ");\n";

    for (auto c : number) {
        if (c == '.') break;

        integerStack.push(c);
    }

    while (!integerStack.empty()) {        
        integer += int(integerStack.top() - '0') * base;
        base *= 10;

        integerStack.pop();
    }

    return integer;
}

string getDecimalPart(const string &number) {
    stringstream ss;
    bool dotFound = false;

    for (auto n : number) {
        if (dotFound) {
            ss << n;
        }
        else if (n == '.') {
            dotFound = true;
        }
    }

    return ss.str();
}

bool strGreater(const string &a, const string &b) {
    for (auto a_it = a.begin(), b_it = b.begin(); a_it != a.end() && b_it != b.end(); ++a_it, ++b_it) {
        if (*a_it == *b_it) continue;
        else return *a_it > *b_it;
    }

    return true;
}