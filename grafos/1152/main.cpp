#include <iostream>
using namespace std;

int main (void) {
    int M, N,
        X, Y, Z;

    while (cin >> M >> N, M != 0 || N != 0) {
        cin >> X >> Y >> Z;

        cout << X << " " << Y << " " << Z << endl;
    }

    return 0;
}
