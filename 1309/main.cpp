/*
Formatação Monetária
https://www.urionlinejudge.com.br/judge/pt/problems/view/1309
*/

#include <iostream>
#include <iomanip>

using namespace std;

void printCurrency(int dollars, int cents);
void printDollars(int dollars);
void printCents(int cents);

int main(void) {
    ios::sync_with_stdio(false);

    int dollars, cents;

    while (cin >> dollars >> cents) {
        printCurrency(dollars, cents);
    }

    return 0;
}

void printCurrency(int dollars, int cents) {
    printDollars(dollars);
    printCents(cents);
}

void printDollars(int dollars) {
    if (dollars < 1000) {
        cout << '$' << dollars;
    }
    else {
        printDollars(dollars / 1000);
        cout << ',' << setw(3) << setfill('0') << (dollars % 1000);
    }
}

void printCents(int cents) {
    cout << '.' << setw(2) << setfill('0') << cents << endl;
}
