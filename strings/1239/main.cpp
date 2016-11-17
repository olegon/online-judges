#include <iostream>
#include <string>

using namespace std;

void imprimirFormatado(const string &line);

int main(void) {
    string line;

    while (getline(cin, line)) {
        imprimirFormatado(line);
    }

    return 0;
}

void imprimirFormatado(const string &line) {
    bool bold = false;
    bool italic = false;

    for (string::const_iterator it = line.begin(); it != line.end(); ++it) {
        if (*it == '*') {
            if (bold) {
                cout << "</b>";
                bold = false;
            }
            else {
                cout << "<b>";
                bold = true;
            }
        }
        else if (*it == '_') {
            if (italic) {
                cout << "</i>";
                italic = false;
            }
            else {
                cout << "<i>";
                italic = true;
            }
        }
        else {
            cout << *it;
        }
    }

    cout << '\n';
}
