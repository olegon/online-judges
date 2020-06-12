/*
Strings: Making Anagrams
https://www.hackerrank.com/challenges/ctci-making-anagrams
*/

#include <bits/stdc++.h>

using namespace std;

int solve(string &A, string &B) {
    unordered_map<char, int> lettersMap;

    int allLettersCount = A.length() + B.length();

    for (char c : A) {
        auto letterMapElement = lettersMap.find(c);
        
        if (letterMapElement == lettersMap.end()) {
            lettersMap.insert({ c, 1 });
        }
        else {
            letterMapElement->second += 1;
        }
    }

    for (char c : B) {
        auto letterMapElement = lettersMap.find(c);
        if (letterMapElement != lettersMap.end()) {
            letterMapElement->second -= 1;

            allLettersCount -= 2;

            if (letterMapElement->second == 0) {
                lettersMap.erase(letterMapElement);
            }
        }
    }

    return allLettersCount;
}

int main(void) {
    ios::sync_with_stdio(false);

    string A, B;

    getline(cin, A);
    getline(cin, B);

    cout << solve(A, B) << endl;

    return EXIT_SUCCESS;
}

