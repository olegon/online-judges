/*
Inversão
https://www.urionlinejudge.com.br/judge/pt/problems/view/1550
*/

#include <bits/stdc++.h>

using namespace std;

struct COST_SO_FAR {
    int NUMBER;
    int COST;
};

int revert(int number) {
    string numberAsString = to_string(number);
    reverse(numberAsString.begin(), numberAsString.end());
    return stoi(numberAsString);
}

int main(void) {
    ios::sync_with_stdio(false);

    int T;

    cin >> T;

    while (T-- > 0) {
        int A, B;

        cin >> A >> B;

        queue<COST_SO_FAR> s;
        unordered_set<int> visited;

        s.push({ A, 0 });

        int COST = 0;

        while (!s.empty()) {
            const auto &current = s.front();
            s.pop();

            visited.insert(current.NUMBER);

            if (current.NUMBER == B) {
                COST = current.COST;
                break;
            }
            else {
                int NEXT = current.NUMBER + 1;
                int REVERTED = revert(current.NUMBER);
                int NEW_COST = current.COST + 1;
                
                if (visited.find(NEXT) == visited.end()) {
                    s.push({ NEXT, NEW_COST });
                }

                if (visited.find(REVERTED) == visited.end()) {
                   s.push({ REVERTED, NEW_COST });
                }
            }
        }

        cout << COST << endl;
    }

    return EXIT_SUCCESS;
}
