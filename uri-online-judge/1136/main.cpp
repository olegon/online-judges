/*
Bingo!
https://www.urionlinejudge.com.br/judge/pt/problems/view/1136
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_set>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    size_t N, B;
    
    while (cin >> N >> B, N != 0 || B != 0) {
        vector<int> bolas(B);
        unordered_set<int> comb;
        
        for (size_t i = 0; i < B; i++) {            
            cin >> bolas[i];
        }

        for (size_t i = 0; i < B; i++) {
            for (size_t j = 0; j < B; j++) {
                comb.insert(abs(bolas[i] - bolas[j]));
                comb.insert(abs(bolas[j] - bolas[i]));
            }
        }

        if (comb.size() == N + 1) cout << "Y\n";
        else cout << "N\n";
    }

    return EXIT_SUCCESS;
}
