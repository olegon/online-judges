# 22. Generate Parentheses
# https://leetcode.com/problems/generate-parentheses

import array
import bisect
import collections
import sortedcontainers

class Solution:
    def __init__(self):
        self.c = []

    def generateParenthesis(self, n: int) -> List[str]:
        self.n = n
        self._generateParenthesis('', 0, 0)
        return self.c

    def _generateParenthesis(self, s, o, c):
        if o > self.n or c > self.n:
            return
        elif len(s) == self.n * 2:
            self.c.append(s)
        elif o > c:
            self._generateParenthesis(s + ')', o, c + 1)
            self._generateParenthesis(s + '(', o + 1, c)
        else:
            self._generateParenthesis(s + '(', o + 1, c)