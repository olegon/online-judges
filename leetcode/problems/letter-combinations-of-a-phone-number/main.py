# 17. Letter Combinations of a Phone Number
# https://leetcode.com/problems/letter-combinations-of-a-phone-number

digitToLetterMap = {
    '2': [ 'a', 'b', 'c' ],
    '3': [ 'd', 'e', 'f' ],
    '4': [ 'g', 'h', 'i' ],
    '5': [ 'j', 'k', 'l' ],
    '6': [ 'm', 'n', 'o' ],
    '7': [ 'p', 'q', 'r', 's' ],
    '8': [ 't', 'u', 'v' ],
    '9': [ 'w', 'x', 'y', 'z' ]
}

def compute(digits, index):
    digit = digits[index]
    letters = digitToLetterMap[digit]

    if index == 0:
        return letters
    else:
        previousPossibilities = compute(digits, index - 1)

        return [
            previousPossibility + letter
            for previousPossibility in previousPossibilities
            for letter in digitToLetterMap[digit]
        ]

class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
        if digits == '':
            return []
        else:
            return compute(digits, len(digits) - 1)
        
    
