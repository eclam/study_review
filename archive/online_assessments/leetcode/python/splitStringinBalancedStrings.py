# Source: https://leetcode.com/problems/split-a-string-in-balanced-strings/
"""
# Cases to consider:
    Base Case:
    - R...R L...L <= R and L are same length

    Special Cases:
    - LR <= L starting first : R and L need to be commutative
    - RLLR <= letters that are the same that are beside each other
    - RRRLL <= uneven case : there 
"""

class Solution:
    def initialSolnBalancedStringSplit(self, s: str) -> int:
        count = 0
        Lcount = 0
        Rcount = 0
        for i in s:
            if Rcount == Lcount and Rcount > 0:
                count += 1
                Lcount = 0
                Rcount = 0

            if i == "R":
                Rcount += 1
            else:
                Lcount += 1

        if Rcount == Lcount and Rcount > 0:
            count += 1

        return count

    def balancedStringSplit(self, s: str) -> int:
        count = 0
        counter = 0
        for i in s:
            if i == 'R':
                counter += 1
            else:
                counter -= 1
            if counter == 0:
                count += 1
        return count

s = input()
soln = Solution()
print(str(soln.balancedStringSplit(s)))