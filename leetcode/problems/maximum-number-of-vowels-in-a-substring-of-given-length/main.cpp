/*
1456. Maximum Number of Vowels in a Substring of Given Length
https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) const {
        int local_max = 0;
        int global_max = 0;

        for (int i = 0; i < k; i++) {
            if (isVowel(s, i)) local_max++;

            global_max = max(local_max, global_max);

            if (global_max == k) return global_max;
        }

        for  (size_t i = k; i < s.size(); i++) {
            if (isVowel(s, i)) local_max++;

            if (isVowel(s, i - k)) local_max--;

            global_max = max(local_max, global_max);

            if (global_max == k) return global_max;
        }

        return global_max;
    }

    inline bool isVowel(string& s, int pos) const {
        char c = s[pos];

        return c == 'a'
            || c == 'e'
            || c == 'i'
            || c == 'o'
            || c == 'u';
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
