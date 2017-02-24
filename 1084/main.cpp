/*
Apagando e Ganhando
https://www.urionlinejudge.com.br/judge/pt/problems/view/1084
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, char> ic;

int main(void) {
    ios::sync_with_stdio(false);

    int N, D;

    while (cin >> N >> D >> ws, N != 0 || D != 0) {
        string number;
        vector<ic*> indexCharacters;

        getline(cin, number);

        for (int i = 0; i < N; i++) {
            ic *indexCharacter = new ic(i, number[i]);
            indexCharacters.push_back(indexCharacter);
        }    

        sort(indexCharacters.begin(), indexCharacters.end(), [] (ic *a, ic *b) -> bool {
            if (a->second == b->second) {
                return a->first < b->first;
            }
            else {
                return a->second < b->second;
            }
        });

        sort(indexCharacters.begin() + D, indexCharacters.end(), [] (ic *a, ic *b) -> bool {
            return a->first < b->first;
        });

        for (int i = D; i < N; i++) {
            // cout << "(" << indexCharacters[i]->first << ", " << indexCharacters[i]->second << ") ";
            cout << indexCharacters[i]->second;
        }

        // for (int i = 0; i < N; i++) free(indexCharacters[i]);

        cout << '\n';
    }    

    return EXIT_SUCCESS;
}
