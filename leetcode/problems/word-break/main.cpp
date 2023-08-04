/*
139. Word Break
https://leetcode.com/problems/word-break
*/

#include <bits/stdc++.h>

using namespace std;

const char DP_DUNNO = '?';
const char DP_FALSE = 'Y';
const char DP_TRUE = 'N';

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        vector<vector<char>> dp(s.size() + 1, vector<char>(s.size() + 2, DP_DUNNO));

        for (string& word: wordDict) {
            words.insert(word);
        }

        return wordBreak(s, 0, 1, words, dp);
    }

    bool wordBreak(string& s, size_t index, size_t length, unordered_set<string>& words, vector<vector<char>> &dp) {
        char result = dp[index][length];

        if (result == DP_DUNNO) {
            if (index >= s.size()) {
                result = DP_TRUE;
            }
            else if (index + length > s.size()) {
                result = DP_FALSE;
            }
            else if (words.find(s.substr(index, length)) != words.end()) {
                result = wordBreak(s, index + length, 1, words, dp) || wordBreak(s, index, length + 1, words, dp)
                        ? DP_TRUE
                        : DP_FALSE;
            }
            else {
                result = wordBreak(s, index, length + 1, words, dp)
                        ? DP_TRUE
                        : DP_FALSE;
            }

            dp[index][length] = result;
        }
       
        return result == DP_TRUE;
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
