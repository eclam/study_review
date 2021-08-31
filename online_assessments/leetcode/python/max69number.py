# Source : https://leetcode.com/problems/maximum-69-number/

class Solution:
    def maximum69Number (self, num: int) -> int:
        stringNum = str(num)
        for i, c in enumerate(stringNum):
            if c == '6':
                return int(stringNum[:i] + '9' + stringNum[i+1:])
        return num

num = int(input())
soln = Solution()
print(soln.maximum69Number(num))