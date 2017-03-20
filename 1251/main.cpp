/*
Diga-me a Frequência
https://www.urionlinejudge.com.br/judge/pt/problems/view/1251
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    string line;

    bool first = true;

    while (getline(cin, line)) {
        if (first) {
            first = false;
        }
        else {
            cout << '\n';
        }

        unordered_map<char, int> charCountMap;

        for (auto it = line.begin(); it != line.end(); ++it) {
            auto entry = charCountMap.find(*it);

            if (entry == charCountMap.end()) {
                charCountMap.insert(make_pair(*it, 1));
            }
            else {
                entry->second++;
            }
        }

        vector<pair<char, int>> pairs(charCountMap.begin(), charCountMap.end());

        sort(pairs.begin(), pairs.end(), [] (const pair<char, int> &a, const pair<char, int> &b) -> bool {
            if (a.second == b.second) return a.first > b.first;
            else return a.second < b.second;
        });

        for (auto it = pairs.begin(); it != pairs.end(); ++it) {
            char character = it->first;
            int count = it->second;

            cout << int(character) << " " << count << '\n';
        }
    }

    return EXIT_SUCCESS;
}
