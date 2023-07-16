/*
9. Palindrome Number
https://leetcode.com/problems/palindrome-number/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        return isPalindrome(str, 0, str.size() - 1);
    }

    bool isPalindrome(string &s, size_t begin, size_t end) {
        if (begin >= end) return true;
        else if (s[begin] == s[end]) return isPalindrome(s, begin + 1, end - 1);
        else return false;
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    int number;
    cin >> number;

    Solution s;
    cout << (s.isPalindrome(number) ? "true" : "false") << endl;

    return EXIT_SUCCESS;
}
