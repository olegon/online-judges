# 459. Repeated Substring Pattern
# https://leetcode.com/problems/repeated-substring-pattern

class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        stringLength = len(s)
        # print(f"stringLength: {stringLength}")

        for substringLength in range(1, stringLength):
            # print(f"substringLength: {substringLength}")

            if stringLength % substringLength == 0:
                substring = s[0:substringLength]
                # print(f"substring: {substring}")
                isSubstringPattern = True

                for startIndex in range(stringLength // substringLength):
                    _substring = s[startIndex * substringLength:startIndex * substringLength + substringLength]
                    # print(f"_substring: {_substring}")
                    if _substring != substring:
                        isSubstringPattern = False
                        break

                if isSubstringPattern:
                    return True
                else:
                    continue
            else:
                continue

        return False