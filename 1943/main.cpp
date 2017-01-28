/*
Top N
https://www.urionlinejudge.com.br/judge/pt/problems/view/1943
*/

#include <iostream>

using namespace std;

void printTop(int K);

int main(void) {
    ios::sync_with_stdio(false);

    int K;

    cin >> K;

    printTop(K);

    return 0;
}

void printTop(int K) {
    int top;

    if (K <= 1) {
        top = 1;
    }
    else if (K <= 3) {
        top = 3;
    }
    else if (K <= 5) {
        top = 5;
    }
    else if (K <= 10) {
        top = 10;
    }
    else if (K <= 25) {
        top = 25;
    }
    else if (K <= 50) {
        top = 50;
    }
    else {
        top = 100;
    }

    cout << "Top " << top << endl;
}
