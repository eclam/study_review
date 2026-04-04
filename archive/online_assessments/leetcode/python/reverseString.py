# Source: https://leetcode.com/problems/reverse-string/
from typing import List
class Solution:
    def unoptimalSoln_reverseString(self, s: List[str]) -> None:
        s_prime = s[::-1]
        for idx, val in enumerate(s_prime):
            s[idx] = val

    def reverseString(self, s: List[str]) -> None: # Made this one first
        """
        Do not return anything, modify s in-place instead.
        """
        lengthStr = len(s)
        halfLen = int(len(s)/2)

        for i in range(halfLen):
            temp = s[i]
            s[i] = s[lengthStr-1-i]
            s[lengthStr-1-i] = temp
        # s_prime = s[::-1]
        # for idx, val in enumerate(s_prime):
        #     s[idx] = val

s = ["h","e","l","l","o"]
soln = Solution()
soln.reverseString(s)


s = ["H", "a", "n", "n", "a", "h"]
soln.reverseString(s)