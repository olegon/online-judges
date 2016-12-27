/*
Troca de Cartas
https://www.urionlinejudge.com.br/judge/pt/problems/view/1104
*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int many(vector<int> &SA, vector<int> &SB);

int main (void) {
    int A, B;

    while (cin >> A >> B, A != 0 || B != 0) {
        set<int> SA, SB;

        for (int i = 0; i < A; i++) {
            int N;

            cin >> N;

            SA.insert(N);
        }

        for (int i = 0; i < B; i++) {
            int N;

            cin >> N;

            SB.insert(N);
        }

        vector<int> CA, CB;

        for (set<int>::iterator it = SA.begin(); it != SA.end(); ++it) {
            CA.push_back(*it);
        }

        for (set<int>::iterator it = SB.begin(); it != SB.end(); ++it) {
            CB.push_back(*it);
        }

        cout << many(CA, CB) << "\n";
    }

    return 0;
}

int many(vector<int> &SA, vector<int> &SB) {
    int CA = 0,
        CB = 0;

    for (int i = 0; i < SA.size(); i++) {
        if (!binary_search(SB.begin(), SB.end(), SA[i])) CA++;
    }

    for (int i = 0; i < SB.size(); i++) {
        if (!binary_search(SA.begin(), SA.end(), SB[i])) CB++;
    }

    return min(CA, CB);
}
