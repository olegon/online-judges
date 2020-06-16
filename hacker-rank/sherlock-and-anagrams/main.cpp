/*
Sherlock and Anagrams
https://www.hackerrank.com/challenges/sherlock-and-anagrams
*/

#include <bits/stdc++.h>

using namespace std;

const size_t LETTERS_SIZE = 'z' - 'a' + 1;

string hashFrom(string &line, size_t start, size_t size) {
    stringstream ss;
    vector<int> occurencies(LETTERS_SIZE, 0);

    for (size_t i = 0; i < size; i++) {
        occurencies[line[start + i] - 'a'] += 1;
    }

    // for (size_t i = 0; i < LETTERS_SIZE; i++) {
    //     cout << char(i + 'a');
    // }
    // cout << endl;

    for (size_t i = 0; i < LETTERS_SIZE; i++) {
        ss << occurencies[i];
    }

    return ss.str();
}

int main(void) {
    ios::sync_with_stdio(false);

    int Q;

    cin >> Q >> ws;

    while (Q-- > 0) {
        string line;
        size_t occurencies = 0;

        getline(cin, line);
        
        for (size_t size = 1; size < line.size(); size++) {
            unordered_map<string, int> hashMap;
            
            for (size_t start = 0; start + size <= line.size(); start++) {
                // cout << "size = " << size << " start = " << start << endl;
                string hash = hashFrom(line, start, size);
                // cout << hash << endl;
                // cout << line.substr(start, size) << endl;

                auto hashElement = hashMap.find(hash);

                if (hashElement == hashMap.end()) {
                    hashMap.insert({ hash, 1 });
                }
                else {
                    occurencies += hashElement->second;
                    hashElement->second++;
                }
            }
        }

        cout << occurencies << endl;

    }

    return EXIT_SUCCESS;
}
