/*
Conversão entre Bases
https://www.urionlinejudge.com.br/judge/pt/problems/view/1193
*/

#include <iostream>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

int fromBin(const string &number);
int fromDec(const string &number);
int fromHex(const string &number);

char getHexDigit(int decimal);

void printBin(int decimal);
void printDec(int decimal);
void printHex(int decimal);

int main(void) {
    int N;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        string numero, base;

        cin >> numero >> base;

        cout << "Case " << i << ":\n";

        if (base == "bin") {
            int decimal = fromBin(numero);

            printDec(decimal);
            printHex(decimal);
        }
        else if (base == "dec") {
            int decimal = fromDec(numero);

            printHex(decimal);
            printBin(decimal);
        }
        else /*if (base == hex) */ {
            int decimal = fromHex(numero);

            printDec(decimal);
            printBin(decimal);
        }

        cout << '\n';
    }

    return 0;
}

int fromBin(const string &number) {
    int result = 0;
    int N = number.length();
    int b = round(pow(2, N - 1));

    for (int i = 0; i < N; i++) {
        result += (number[i] - '0') * b;
        b /= 2;
    }

    return result;
}

int fromDec(const string &number) {
    int result = 0;
    int N = number.length();
    int b = round(pow(10, N - 1));

    for (int i = 0; i < N; i++) {
        result += (number[i] - '0') * b;
        b /= 10;
    }

    return result;
}

int fromHex(const string &number) {
    int result = 0;
    int N = number.length();
    int b = round(pow(16, N - 1));

    for (int i = 0; i < N; i++) {
        if (number[i] >= '0' && number[i] <= '9') result += (number[i] - '0') * b;
        else if (number[i] >= 'a' && number[i] <= 'f') result += (number[i] - 'a' + 10) * b;
        else if (number[i] >= 'A' && number[i] <= 'F') result += (number[i] - 'A' + 10) * b;
        b /= 16;
    }

    return result;
}

void printBin(int decimal) {
    stack<int> digits;

    while (true) {
        if (decimal < 2) {
            digits.push(decimal);
            break;
        }
        else {
            digits.push(decimal % 2);
            decimal /= 2;
        }
    }

    while (digits.size() > 0) {
        cout << digits.top();
        digits.pop();
    }

    cout << " bin\n";
}

void printDec(int decimal) {
    cout << decimal << " dec\n";
}

char getHexDigit(int decimal) {
    if (decimal < 10) {
        return decimal + '0';
    }
    else {
        return (decimal - 10) + 'a';
    }
}

void printHex(int decimal) {
    stack<char> digits;

    while (true) {
        if (decimal < 16) {
            digits.push(getHexDigit(decimal));
            break;
        }
        else {
            digits.push(getHexDigit(decimal % 16));
            decimal /= 16;
        }
    }

    while (digits.size() > 0) {
        cout << digits.top();
        digits.pop();
    }

    cout << " hex\n";
}
