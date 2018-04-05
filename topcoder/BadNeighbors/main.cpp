/*
Problem Name:   BadNeighbors
Used In:        TCCC '04 Round 4
Used As:        Division I Level One
Categories:     Dynamic Programming

https://community.topcoder.com/tc?module=ProblemDetail&rd=5009&pm=2402
*/

#include <iostream>
#include <vector>

using namespace std;

int bestOption(vector<int> doacoes, bool primeiroEscolhido, int ultimoEscolhido, size_t i) {
    if (i == 0) {
        int a = bestOption(doacoes, false, -1, i + 1);
        int b = doacoes[0] + bestOption(doacoes, true, 0, i + 1);
        
        return max(a, b);
    }
    else if (i == doacoes.size() - 1 && primeiroEscolhido) {
        return 0;
    }
    else if (i < doacoes.size()) {
        if (ultimoEscolhido + 1 == i) {
            return bestOption(doacoes, primeiroEscolhido, ultimoEscolhido, i + 1);
        }
        else {
            int a = bestOption(doacoes, primeiroEscolhido, ultimoEscolhido, i + 1);
            int b = doacoes[i] + bestOption(doacoes, primeiroEscolhido, i, i + 1);
            
            return max(a, b);
        }
    }
    else {
        return 0;
    }
}

class BadNeighbors {
public:
    int maxDonations(vector<int> donations);
};

int BadNeighbors::maxDonations(vector<int> donations) {
    return bestOption(donations, false, -1, 0);
}

int main(void) {
    vector<int> v = { 10, 3, 2, 5, 7, 8 };
    // vector<int> v = { 7, 7, 7, 7, 7, 7, 7 };
    // vector<int> v = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
    // vector<int> v = { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61, 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397, 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };

    cout << BadNeighbors().maxDonations(v) << endl;

    return 0;
}
