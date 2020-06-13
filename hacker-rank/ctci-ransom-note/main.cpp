/*
Hash Tables: Ransom Note
https://www.hackerrank.com/challenges/ctci-ransom-note
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int M, N;
    string word;
    bool match = true;
    unordered_map<string, int> magazine_words;

    cin >> M >> N;
    

    while (M-- > 0) {
        cin >> word;

        auto magazine_word_result = magazine_words.find(word);

        if (magazine_word_result == magazine_words.end()) {
            magazine_words.insert({ word, 1 });
        }
        else {
            magazine_word_result->second++;
        }
    }

    cin >> ws;

    while (N-- > 0) {
        cin >> word;

        auto magazine_word_result = magazine_words.find(word);

        if (magazine_word_result == magazine_words.end()) {
            match = false;
            break;
        }
        else {
            magazine_word_result->second--;

            if (magazine_word_result->second == 0) {
                magazine_words.erase(magazine_word_result);
            }
        }
    }

    cout << (match ? "Yes" : "No") << endl;

    return EXIT_SUCCESS;
}
