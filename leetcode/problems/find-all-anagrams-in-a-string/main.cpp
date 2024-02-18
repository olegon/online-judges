/*
438. Find All Anagrams in a String
https://leetcode.com/problems/find-all-anagrams-in-a-string
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        unordered_map<char, int> charToFreqP;
        unordered_map<char, int> charToFreqS;
        size_t k = p.size();

        for (char c = 'a'; c <= 'z'; c++) {
            charToFreqS[c] = 0;
            charToFreqP[c] = 0;
        }

        for (char c : p) charToFreqP[c]++;

        for (size_t i = 0; i < k; i++) {
            charToFreqS[s[i]]++;

            if (charToFreqP == charToFreqS) result.push_back(0);
        }

        for (size_t i = k; i < s.size(); i++) {
            charToFreqS[s[i]]++;
            charToFreqS[s[i - k]]--;

            if (charToFreqP == charToFreqS) result.push_back(i - k + 1);
        }

        return result;
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
