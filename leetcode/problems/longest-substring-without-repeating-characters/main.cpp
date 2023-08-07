/*
3. Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters
*/

#include <bits/stdc++.h>

using namespace std;

// O(n) solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t firstIndex = 0;
        size_t lastIndex = 0;
        size_t longest = 0;
        map<char, size_t> characterToIndex;
        
        while (lastIndex < s.size()) {
            char character = s[lastIndex];

            auto search = characterToIndex.find(character);
            if (search == characterToIndex.end() || search->second < firstIndex) {
                longest = max(longest, lastIndex - firstIndex + 1);
                characterToIndex[character] = lastIndex;
            }
            else {
                firstIndex = search->second + 1;
                search->second = lastIndex;
            }

            lastIndex++;
        }
        
        return longest;
    }
};

class QuadraticSolution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t longest = 0;
        
        for (size_t i = 0; i < s.size(); i++) {
            size_t localLongest = 0;
            unordered_set<char> uniqueChars;
            
            for (size_t j = i; j < s.size(); j++) {
                char c = s[j];

                if (uniqueChars.find(c) == uniqueChars.end()) {
                    uniqueChars.insert(c);
                    localLongest += 1;
                    longest = max(localLongest, longest);
                }
                else {
                    break;
                }
            }
        }

        return longest;
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
