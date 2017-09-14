/*
Ordenação por Tamanho

https://www.urionlinejudge.com.br/judge/pt/problems/view/1244
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare_by_size(string a, string b);

int main (void) {
    int N;
    string LINE;

    cin >> N;
    cin.ignore(1);

    for (int i = 0; i < N; i++) {
        string word;
        vector<string> words;

        getline(cin, LINE);

        istringstream ss(LINE);

        while (getline(ss, word, ' ')) {
            words.push_back(word);
        }

        stable_sort(words.begin(), words.end(), compare_by_size);

        for (size_t i = 0; i < words.size(); i++) {
            if (i != 0) {
                cout << " ";
            }
            cout << words[i];
        }

        cout << endl;
    }


    return 0;
}

bool compare_by_size(string a, string b) {
    return a.size() > b.size();
}
